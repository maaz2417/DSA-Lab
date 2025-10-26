#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
    Node(int i): id(i), next(nullptr) {}


};

int main() {

    const int M = 10;
    const int N = 3;

    Node* head = new Node(1);
    Node* tail = head;
    for (int i = 2; i <= M; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    cout << "ORIGNAL :" << head << endl;
    tail->next = head;

    cout << "Elimination order: ";
    Node* prev = tail;
    Node* curr = head;

    while (curr->next != curr) {
        for (int count = 1; count < N; ++count) {
            prev = curr;
            curr = curr->next;
        }

        cout << curr->id;


        prev->next = curr->next;
        Node* toDelete = curr;
        curr = curr->next;
        delete toDelete;

    
        if (curr->next != curr) cout << " ";
    }

    cout << "\nSurvivor: " << curr->id << endl;
    return 0;
}