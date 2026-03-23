#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front;
    int rear;
    int size;
    int elementCount;

public:
    Queue(int s) {
        arr = new int[s];
        size = s;
        front = 0;
        rear = -1;
        elementCount = 0;
    }

    bool isFull() {
        return elementCount == size;
    }

    bool isEmpty() {
        return elementCount == 0;
    }

    void enqueue(int val) {
        if (isFull()) return;
        rear = (rear + 1) % size;
        arr[rear] = val;
        elementCount++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        front = (front + 1) % size;
        elementCount--;
        return val;
    }

    int getCount() {
        return elementCount;
    }
};

void reverseFirstKHelper(Queue &q, int k) {
    if (k == 0) return;
    int val = q.dequeue();
    reverseFirstKHelper(q, k - 1);
    q.enqueue(val);
}

void reverseFirstK(Queue &q, int k) {
    if (k <= 0 || k > q.getCount()) return;
    reverseFirstKHelper(q, k);
    int rem = q.getCount() - k;
    while (rem--) q.enqueue(q.dequeue());
}

int main() {
    Queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    reverseFirstK(q, 3);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
