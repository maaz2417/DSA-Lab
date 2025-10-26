#include <iostream>
using namespace std;

void printArray(int num[], int size) {
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

void swapEvenOddInd(int nums[], int size) {
    int *p = nums;
    for (int i = 0; i <size/2; i++) {
        int temp = *p;
        *p = *(p + 1);  
        *(p+1) = temp; 
        p = p + 2; // p += 2;
    }
}

void reverseArray (int nums[], int size) {
    int *start = nums;
    int *end = nums + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int size = 6;
    int n[] = {1,2,3,4,5,6};
    cout << "Original array" << endl;
    printArray(n,size);
    cout << "After swapping even and odd indexed elements" << endl;
    swapEvenOddInd(n,size);
    printArray(n,size);
    cout << "After reversing the array" << endl;
    reverseArray(n,size);
    printArray(n,size);
    return 0;
}