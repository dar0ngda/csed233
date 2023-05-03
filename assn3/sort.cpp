#include "sort.h"
#include <iostream>
#include <fstream>
#include <string>


sortAlg::sortAlg() {
    arr_size = 0;
    arr = new int[100]; // Each test case will be less than 100 values
    temp = new int[100];
}

using namespace std;

void sortAlg::printArray(ofstream &fout){
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    fout << answer << endl;
}

string sortAlg::printArray(ofstream &fout, string prev) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);
    if (prev != answer) {
        fout << answer << endl;
    }
    return answer;
}

void sortAlg::swap(ofstream &fout, int a, int b) {
    string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    answer = printArray(fout, answer);
    return;
}

int sortAlg::partition(ofstream &fout, int left, int right) {
    int pivot = arr[left];
    int i = left;
    int temp;

    for (int j = i + 1; j <= right; j++) {
        if (pivot >= arr[j]) {
            i++;
            swap(fout, i, j);
        }
    }
    swap(fout, left, i);

    return i;
}

void sortAlg::quickSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////

    // If swapping happens, print the array values after the swapping using "printArray(fout);"
    // You can freely add other functions (e.g., a function for partitioning) to either sort.cpp or sort.h.
    int p;
    if (left < right) {
        p = partition(fout, left, right);

        quickSort(fout, left, p - 1);
        quickSort(fout, p + 1, right);
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::merge(int left, int mid, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    /*string answer;
    for (int i = 0; i < arr_size - 1; i++)
        answer += to_string(arr[i]) + " ";
    answer += to_string(arr[arr_size - 1]);*/
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i<=mid && j<=right) {
        if (arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    int l = i > mid ? j : i;
    while (k<=right) {
        temp[k++] = arr[l++];
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    //answer = printArray(arr, answer);
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}


void sortAlg::mergeSort(ofstream &fout, int left, int right) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(fout, left, mid);
        mergeSort(fout, mid + 1, right);
        merge(left, mid, right);
        printArray(fout);
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
