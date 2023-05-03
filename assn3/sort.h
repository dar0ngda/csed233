#include <iostream>
#include <string>
using namespace std;

class sortAlg {

public:
    sortAlg();

    int arr_size;
    int *arr;
    int *temp; //for merge sort

    void printArray(ofstream &);
    string printArray(ofstream &, string prev);
    void swap(ofstream &fout, int a, int b);
    int partition(ofstream &fout, int left, int right);
    void quickSort(ofstream &, int left, int right);

    void mergeSort(ofstream &, int left, int right);
    void merge(int left, int mid, int right);


};

