#pragma once
#include <string>

using namespace std;

class Node {
public:
    Node(int key) : key(key), height(0), left(NULL), right(NULL) {}
    int key;
    int height;
    Node *left;
    Node *right;
    /* Add public members if required*/

    string print_key() { return to_string(key); };
};

class BinaryTree {
public:
    BinaryTree() { _root = NULL; };
    ~BinaryTree() {
        delete[] _root;
        _root = NULL;
    };
    string preOrder();
    string inOrder();

protected:
    Node *_root;
    Node* getmin(Node* cur);
    void search(int key, Node* &cur, Node* &par);
    int getheight(Node* cur);

private:
    void _inOrder(string& output, Node *cur);
    void _preOrder(string& output, Node *cur);
};
