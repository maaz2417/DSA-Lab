#include <iostream>
using namespace std;

void show(int *p, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

int getSum(int *p, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += *(p + i);
    }
    return s;
}

void swapEvenOdd(int *p, int n) {
    for (int i = 0; i < n - 1; i += 2) {
        int temp = *(p + i);
        *(p + i) = *(p + i + 1);
        *(p + i + 1) = temp;
    }
}

void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    cout << "Original array: ";
    show(arr, n);
    int s = getSum(arr, n);
    cout << "Sum of array: " << s << endl;
    swapEvenOdd(arr, n);
    cout << "Array after swap: ";
    show(arr, n);
    reverseArray(arr, n);
    cout << "Array after reverse: ";
    show(arr, n);
    delete[] arr;
    return 0;
}