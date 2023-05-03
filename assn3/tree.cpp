#include "tree.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string BinaryTree::inOrder() {
  string output;
  _inOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

string BinaryTree::preOrder() {
  string output;
  _preOrder(output, _root);
  if (!output.empty())
    output.pop_back();
  return output;
}

void BinaryTree::_inOrder(string& output, Node *cur) {
  if(cur == NULL)
      return;

  _inOrder(output, cur->left);
  output.append(cur->print_key());
  output.append(" ");
  _inOrder(output, cur->right);
}

void BinaryTree::_preOrder(string& output, Node *cur) {
  if(cur == NULL)
      return;

  output.append(cur->print_key());
  output.append(" ");
  _preOrder(output, cur->left);
  _preOrder(output, cur->right);
}

Node* BinaryTree::getmin(Node* cur) {
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

int BinaryTree::getheight(Node* cur) {
    int height = 0;
    if (cur) {
        int left = getheight(cur->left);
        int right = getheight(cur->right);
        height = max(left, right) + 1; //algorithm header
    }
    return height;
}

void BinaryTree::search(int key, Node*& cur, Node*& par) {
    while (cur && cur->key != key) {
        par = cur;
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
}

