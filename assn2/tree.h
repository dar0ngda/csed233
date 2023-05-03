#pragma once
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
  Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
  char value;
  Node *left;
  Node *right;
};

class BinaryTree {
public:
  BinaryTree() { _root = NULL; };
  ~BinaryTree() {
    delete[] _root;
    _root = NULL;
  };
  void buildFromString(const char *data);

  string preOrder();
  string postOrder();
  string inOrder();
  string isProper();
  string isFull();
  string isComplete();
  string getDepthHeight(int node_value);
private:
  Node *_root;
  Node *_buildFromString(const char *data, int start, int end);
   
  void printpre(Node* nptr, string& ans) {
    if (nptr) {
      ans.push_back(nptr->value);
      ans.append(" ");
      printpre(nptr->left, ans);
      printpre(nptr->right, ans);
    }
  }

  void printpost(Node* nptr, string& ans) {
    if (nptr) {
      printpost(nptr->left, ans);
      printpost(nptr->right, ans);
      ans.push_back(nptr->value);
      ans.append(" ");
    }
  }

  void printin(Node* nptr, string& ans) {
    if (nptr) {
      printin(nptr->left, ans);
      ans.push_back(nptr->value);
      ans.append(" ");
      printin(nptr->right, ans);
    }
  }

  Node* search(Node* nptr, const char& val) {
    Node* x = NULL;
    if (nptr == NULL){
      return NULL;
    }
    if (nptr->value == val) {
      return nptr;
    }
    x = search(nptr->left, val);
    if (x) return x;
    x = search(nptr->right, val);
    if (x) return x;

    return NULL;
  }
  
  int height(Node* nptr) {
    if (nptr == NULL) {
      return 0;
    }
    return 1 + max(height(nptr->left), height(nptr->right));
  }

  int depth(Node* nptr, const char& val) {
    if (nptr == NULL) return -1;
    int dist = -1;

    if ((nptr->value == val) || (dist = depth(nptr->left, val)) >= 0 || (dist = depth(nptr->right, val)) >= 0) return dist + 1;

    return dist;
  }

  int howmanynodes(Node* nptr) {
    int count = 0;
    if (nptr) {
      count = 1 + howmanynodes(nptr->left) + howmanynodes(nptr->right);
    }
    return count;
  }
  
};