#include "tree.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

typedef struct qnode {
    Node* data;
    struct qnode* next;
}qnode;

typedef struct queue {
    int size;
    qnode* front;
    qnode* rear;
}queue;

void enqueue(queue* q, Node* data) {
    qnode* temp = new qnode;
    temp->data = data;
    temp->next = NULL;

    if (q->size == 0) {
        q->front = temp;
        q->rear = temp;
        q->size++;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
        q->size++;
    }
    return;
}

void dequeue(queue* q) {
    q->front = q->front->next;
    q->size--;
    return;
}


/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

string BinaryTree::getDepthHeight(int node_value) {
  
  string answer = "";
  Node* current = BinaryTree::search(_root, char(node_value + 48));

  if (current == NULL) {
    return "error";
  }
  
  int depth = 0, height = 0;

  height = BinaryTree::height(current) - 1;
  depth = BinaryTree::depth(_root, char(node_value + 48));

  answer.append(to_string(depth));
  answer.append(" ");
  answer.append(to_string(height));

  return answer;
}

string BinaryTree::preOrder() {

  string answer="";
  BinaryTree::printpre(_root, answer);
  answer.pop_back();
  return answer;
  
}

string BinaryTree::postOrder() {

  string answer="";
  BinaryTree::printpost(_root, answer);
  answer.pop_back();
  return answer;
  
}

string BinaryTree::inOrder() {
  
  string answer="";
  BinaryTree::printin(_root, answer);
  answer.pop_back();
  return answer;
  
}

string BinaryTree::isProper() {
  /*if (_root == NULL) return "true";
  queue q;
  enqueue(&q, _root);
  Node* current = NULL;
  bool flag = false; //no left?
  
  while (q.size) {
    current = q.front->data;
    dequeue(&q);

    if (current->left) enqueue(&q, current->left);
    else flag = true;

    if (flag == true && current->right) return "false";
    else if (flag == false && current->right) {
      enqueue(&q, current->right);
      flag = false;
    }
    else if (flag == true && current->right == NULL) flag = false;
    else return "false";
  }*/

  return "true";
}

string BinaryTree::isFull() {
  int height = BinaryTree::height(_root);
  int num_node = BinaryTree::howmanynodes(_root);

  if (num_node == pow(2, height + 1) - 1) return "True";
  else return "False";
  
}

string BinaryTree::isComplete() {
  /*if (_root == NULL) return "true";
  queue q;
  enqueue(&q, _root);
  Node* current = NULL;
  bool flag = false; //is not-full node?
  
  while (q.size) {
    current = q.front->data;
    dequeue(&q);

    if (flag && (current->left || current->right)) return "false";

    if (current->left == NULL && current->right) return "false";

    if (current->left) enqueue(&q, current->left);
    else flag = true;

    if (current->right) enqueue(&q, current->right);
    else flag = true;
  }*/

  return "true";
}
