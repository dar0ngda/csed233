#include "tree.h"
#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

int BinarySearchTree::insertion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    Node* newnode = new Node(key);
    if (_root == NULL) {
        _root = newnode;
        return 0;
    }
    Node* cur = _root;
    Node* tmp = cur;
    while (cur) {
        tmp = cur;
        if (key < cur->key) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    if (key == tmp->key) return -1;
    else if (key < tmp->key) {
        tmp->left = newnode;
        return 0;
    }
    else {
        tmp->right = newnode;
        return 0;
    }

    ///////////      End of Implementation      /////////////
    ///////////////////////////////////////////////////////
}

int BinarySearchTree::deletion(int key) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    int issuccess = 0;
    _deletion(issuccess, key, _root);
    return issuccess;

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////

/*  Write your codes if you have additional functions  */
void BinarySearchTree::_deletion(int& issuccess, int key, Node*& root) {
    Node* par = NULL;
    Node* cur = root;

    search(key, cur, par);

    if (!cur) {
        issuccess = -1;
        return;
    }

    if (!(cur->left) && !(cur->right)) {
        if (cur != root)
        {
            if (par->left == cur) par->left = NULL;
            else par->right = NULL;
        }
        else root = NULL;
        delete cur;
    }
    else if (cur->left && cur->right) {
        Node* suc = getmin(cur->right);
        int suckey = suc->key;
        _deletion(issuccess, suc->key, root);
        cur->key = suckey;
    }
    else {
        Node* child = (cur->left) ? cur->left : cur->right;

        if (cur != root) {
            if (cur == par->left) par->left = child;
            else par->right = child;
        }
        else root = child;
        delete cur;
    }

}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
