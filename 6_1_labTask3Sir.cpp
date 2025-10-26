#include <iostream>
using namespace std;

void printArr(int arr[], int l) {
    for (int i = 0; i < l; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

bool isAscending(int arr[], int l){ 
    int *start = arr;
    int *end = arr + l - 1;

    if(*start < *end) {
        return true;
    }
    else { 
        false;
    }
}
void sortedInsert(int arr[], int l, int c, int val) {
    if (l == c){
        cout << "List is full. Cannot insert!" << endl;
        return;
    }
    int pos = 0;
    int *curr = arr;
    if(isAscending(arr, l)){
        for(int i = 1; i <= l; i++){
            if(val <= *curr){
                break;
            }
        curr++;
        pos++;
    }

    curr = arr + l - 1;
    for (int i = l; i >= pos; i--){
        *(curr + 1) = *curr;
        curr--;
    } 
    *(curr + 1) = val;
    l++;
}
}

int main() {
    const int capacity = 8;
    int arr[capacity] = {1 , 4 , 6 , 11 , 14};
    int length = 5;
    printArr(arr, length);
    sortedInsert(arr, length, capacity, 8);
    printArr(arr, length);
    sortedInsert(arr, length, capacity, 2);
    printArr(arr, length);
}