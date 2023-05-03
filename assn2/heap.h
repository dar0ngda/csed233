#pragma once
#include <iostream>
#include <string>
using namespace std;

class MinHeap {

public:
    MinHeap();

    int heap_size;
    int *heap_arr;

    void minHeapProp(int);
    void insertKey(int);
    void deleteMin();
    void deleteElement(int);
    string printHeap();

private:
    int parent(int idx) {
      return (idx - 1) / 2;
    }
    int left_child(int idx) {
      return 2 * idx + 1;
    }
    int right_child(int idx) {
      return 2 * idx + 2;
    }

};