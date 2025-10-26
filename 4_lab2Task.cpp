#include <iostream>
using namespace std;

double averageStock(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += *(arr + i);
    return (double)sum / n;
}

int countCritical(int *arr, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) if (*(arr + i) < avg) count++;
    return count;
}

int findTopSellingProduct(int *arr, int n) {
    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *(arr + maxIdx)) maxIdx = i;
    }
    return maxIdx;
}

int findSecondBestSeller(int *arr, int n) {
    int first = -1, second = -1;
    for (int i = 0; i < n; i++) {
        if (first == -1 || *(arr + i) > *(arr + first)) {
            second = first;
            first = i;
        } else if ((second == -1 || *(arr + i) > *(arr + second)) && *(arr + i) != *(arr + first)) {
            second = i;
        }
    }
    return second;
}

void sortByPopularity(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + j) > *(arr + i)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter inventory size: ";
    cin >> size;
    int *inv = new int[size];
    cout << "Enter stock for each product: ";
    for (int i = 0; i < size; i++) {
        cin >> *(inv + i);
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) sum += *(inv + i);
    double avg = (double)sum / size;
    cout << "Average: " << avg << endl;
    int crit = 0;
    for (int i = 0; i < size; i++) if (*(inv + i) < avg) crit++;
    cout << "Critical (<avg): " << crit << endl;
    int top = 0;
    for (int i = 1; i < size; i++) if (*(inv + i) > *(inv + top)) top = i;
    cout << "Top product: " << top << " stock: " << *(inv + top) << endl;
    int first = -1, second = -1;
    for (int i = 0; i < size; i++) {
        if (first == -1 || *(inv + i) > *(inv + first)) {
            second = first;
            first = i;
        } else if ((second == -1 || *(inv + i) > *(inv + second)) && *(inv + i) != *(inv + first)) {
            second = i;
        }
    }
    if (second != -1)
        cout << "Second best: " << second << " stock: " << *(inv + second) << endl;
    else
        cout << "No second best." << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(inv + j) > *(inv + i)) {
                int t = *(inv + i);
                *(inv + i) = *(inv + j);
                *(inv + j) = t;
            }
        }
    }
    cout << "Sorted: ";
    for (int i = 0; i < size; i++) {
        cout << *(inv + i) << " " << endl;
    }
}
