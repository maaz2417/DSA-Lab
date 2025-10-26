#include <iostream>
using namespace std;

void swapEvenOddInd(int nums[], int size) {
    int *p = nums;
    for (int i = 0; i <size/2; i++) {
        int temp = *p;
        *p = *(p + 1);  
        *(p+1) = temp; 
        p = p + 2; // p += 2;

    }
}

void printArray(int num[], int size) {
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

}
int main() {
    int size = 6;
    int n[] = {1,2,3,4,5,6};
    printArray(n,size);
    swapEvenOddInd(n,size);
    printArray(n,size);
    return 0;
}