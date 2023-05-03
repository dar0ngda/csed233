#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

MinHeap::MinHeap() {
  heap_size = 0;
  heap_arr = new int[100]; // Default array of size 100
}

string MinHeap::printHeap() {
  string answer;
  for (int i = 0; i < heap_size; i++)
    answer += to_string(heap_arr[i]) + " ";
  return answer;
}

void MinHeap::insertKey(int k) {
  heap_arr[heap_size] = k;
  heap_size++;
  int current_idx = heap_size - 1;
  while (current_idx > 0 && heap_arr[parent(current_idx)] > heap_arr[current_idx]) {
    int temp = heap_arr[parent(current_idx)];
    heap_arr[parent(current_idx)] = heap_arr[current_idx];
    heap_arr[current_idx] = temp;
    current_idx = parent(current_idx);
  }
}

void MinHeap::deleteMin() {
  heap_arr[0] = heap_arr[heap_size - 1];
  heap_size--;
  MinHeap::minHeapProp(0);
}

void MinHeap::minHeapProp(int i) {
  if (heap_size <= 1) return;
  int left = left_child(i);
  int right = right_child(i);
  int min = i;

  if (left < heap_size && heap_arr[left] < heap_arr[i]) min = left;

  if (right < heap_size && heap_arr[right] < heap_arr[min]) min = right;

  if (min != i) {
    int temp = heap_arr[i];
    heap_arr[i] = heap_arr[min];
    heap_arr[min] = temp;
    MinHeap::minHeapProp(min);
  }
}

void MinHeap::deleteElement(int i) {
  heap_arr[i] = heap_arr[0] - 1;
  int current = i;
  while (current > 0 && heap_arr[parent(current)] > heap_arr[current]) {
    int temp = heap_arr[parent(current)];
    heap_arr[parent(current)] = heap_arr[current];
    heap_arr[current] = temp;
    current = parent(current);
  }
  MinHeap::deleteMin();
}