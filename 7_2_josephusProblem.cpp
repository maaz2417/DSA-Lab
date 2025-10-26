#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node(int value) : value(value), next(nullptr) {}
};

class circularLinkedList {
    private:
        Node *head;
        int length;
    public:
        circularLinkedList() {
            head = nullptr;
            length = 0;
        }
        void insert(int val, int pos) {
            if(pos < 1 || pos > length + 1) {
                cout << "INVALID!" << endl;
                return;
            }
            Node *n = new Node(val);
            if (length == 0) {
                head = n;
                head->next = head;
            } else if (pos == 1) {
                Node *tail = head;
                while (tail->next != head) tail = tail->next;
                n->next = head;
                tail->next = n;
                head = n;
            } else {
                Node *curr = head;
                for(int i = 1; i < (pos - 1); i++) {
                    curr = curr->next;
                }
                n->next = curr->next;
                curr->next = n;
            }
            length++;
        }
        void josephus(int n) {
            if (head == nullptr || n < 1) return;
            Node *prev = nullptr;
            Node *curr = head;
            while (length > 1) {
                for (int i = 1; i < n; ++i) {
                    prev = curr;
                    curr = curr->next;
                }
                cout << curr->value;
                prev->next = curr->next;
                if (curr == head) head = curr->next;
                Node *toDelete = curr;
                curr = curr->next;
                delete toDelete;
                length--;
                if (length > 1) cout << " ";
            }
            if (head) {
                cout << "\nSurvivor: " << head->value << endl;
                delete head;
                head = nullptr;
                length = 0;
            }
        }
};

int main(){
    circularLinkedList cl;
    const int M = 10;
    const int N = 3;
    for (int i = 1; i <= M; i++) cl.insert(i, i);
    cl.josephus(N);
    return 0;
}