#include <iostream>
using namespace std;

bool isAscending(int* arr, int length) {
    if(length < 2)
        return true;
    for (int i = 1; i < length; i++) {
        if (arr[i] < arr[i-1])
            return false;
    }
    return true;
}

void sortedInsert(int* arr, int& length, int val) {
    bool ascending = isAscending(arr, length);
    int pos = 0;

    if (ascending) {
        while (pos < length && arr[pos] < val) {
            pos++;
        }
    }

    else { 
        while (pos < length && arr[pos] > val){
            pos++;
        }
    }
    for (int i = length; i > pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos] = val;
    length++;
}

int main() {
    int size; 
    cout << "Enter the of the array (number of elements) : ";
    cin >> size;
    
    if (size < 1) {
        cout << "Size must be positive!\n";
        return 1;
    }

    int * arr = new int [size + 1];
    cout << "Enter " << size << " sorted elements" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int val;
    cout << "Enter the value you want to insert"<< endl;
    cin >> val;

    int length = size;
    sortedInsert(arr, length, val);

    cout << "Array after insertion of the value" << endl;
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
        cout << endl;
        delete[] arr;
        return 0;
}
