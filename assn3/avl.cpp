#include "tree.h"
#include "bst.h"
#include "avl.h"
#include <iostream>
#include <string>

using namespace std;


/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */
int AVLTree::diff_h(Node* cur) {
    int left = getheight(cur->left);
    int right = getheight(cur->right);
    return left - right;
}

Node* AVLTree::RRrot(Node* cur) {
    Node* tmp = cur->right;
    cur->right = tmp->left;
    tmp->left = cur;
    return tmp;
}
Node* AVLTree::LLrot(Node* cur) {
    Node* tmp = cur->left;
    cur->left = tmp->right;
    tmp->right = cur;
    return tmp;
}
Node* AVLTree::RLrot(Node* cur) {
    Node* tmp = cur->right;
    cur->right = LLrot(tmp);
    return RRrot(cur);
}
Node* AVLTree::LRrot(Node* cur) {
    Node* tmp = cur->left;
    cur->left = RRrot(tmp);
    return LLrot(cur);
}

Node* AVLTree::balancing(Node* cur) {
    int diff = diff_h(cur);
    if (diff > 1) {
        if (diff_h(cur->left) > 0) cur = LLrot(cur);
        else cur = LRrot(cur);
    }
    else if (diff < -1) {
        if (diff_h(cur->right) > 0) cur = RLrot(cur);
        else cur = RRrot(cur);
    }
    //balancing(cur->left);
    //balancing(cur->right);
    return cur;
}

Node* AVLTree::_insertion(int& issuccess, int key, Node* cur) {
    Node* newnode = new Node(key);
    if (cur == NULL) {
        cur = newnode;
        return newnode;
    }

    if (key < cur->key) cur->left = _insertion(issuccess, key, cur->left);
    else if (key > cur->key) cur->right = _insertion(issuccess, key, cur->right);
    else {
        issuccess = -1;
        return cur;
    }

    return balancing(cur);

}

Node* AVLTree::_deletion(int& issuccess, int key, Node* cur) {
    if (!cur) {
        issuccess = -1;
        return cur;
    }
    if (key < cur->key) cur->left = _deletion(issuccess, key, cur->left);
    else if (key > cur->key) cur->right = _deletion(issuccess, key, cur->right);
    else {
        if (!(cur->left) || !(cur->right)) {
            Node* tmp = NULL;
            if (tmp == cur->left) tmp = cur->right;
            else tmp = cur->left;
            if (!tmp) {
                tmp = cur;
                cur = NULL;
            }
            else cur = tmp;
        }
        else {
            Node* tmp = getmin(cur->right);
            cur->key = tmp->key;
            cur->right = _deletion(issuccess, tmp->key, cur->right);
        }
    }
    if (cur == NULL) return cur;
    return balancing(cur);
}

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////


int AVLTree::insertion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    int issuccess = 0;
    _root = _insertion(issuccess, key, _root);
    return issuccess;

    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int AVLTree::deletion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    int issuccess = 0;
    _root = _deletion(issuccess, key, _root);
    return issuccess;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
