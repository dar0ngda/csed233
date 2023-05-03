#pragma once
#include "bst.h"

using namespace std;

class AVLTree: public BinarySearchTree {
public:
    AVLTree() { };
    ~AVLTree() { };

    int insertion(int key);
    int deletion(int key);

private:
    /////////////////////////////////////////////////////////
    //////  TODO: Add private members if required ///////////
    int diff_h(Node* cur);

    Node* RRrot(Node* cur);
    Node* LLrot(Node* cur);
    Node* RLrot(Node* cur);
    Node* LRrot(Node* cur);

    Node* balancing(Node* cur);

    Node* _insertion(int& issuccess, int key, Node* cur);
    Node* _deletion(int& issuccess, int key, Node* cur);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};