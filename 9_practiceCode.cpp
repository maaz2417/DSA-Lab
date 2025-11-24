#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data){
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
};

class LinkedList{
    private:
        Node *head;
        Node *curr;
        int length;

    public:
        LinkedList(){
            curr = head = nullptr;
            length = 0;
        }
        void insert(int val, int pos){
            if(pos < 1 || pos > length + 1){
                cout << "Invalid Position." << endl;
                return;
            }
            Node *n = new Node(val);
            if (pos == 1){
                n->next = head;
                n->prev = nullptr;
                if (head != nullptr) head->prev = n;
                head = n;
            }
            else{
                curr = head;
                for (int i = 1; i < pos - 1; i++){
                    curr = curr->next;
                }
                n->next = curr->next;
                n->prev = curr;
                if (curr->next != nullptr){
                    curr->next->prev = n;
                }
                curr->next = n;
            }
            length++;
        }
        void remove(int pos){
            if(pos < 1 || pos > length){
                return;
            }
            if (head == nullptr) return;
            if(pos == 1){
                curr = head;
                head = head->next;
                if (head != nullptr) head->prev = nullptr;
                delete curr;
            } else {
                curr = head;
                for(int i = 1; i < pos; i++){
                    curr = curr->next;
                }
                if (curr->next != nullptr){
                    curr->next->prev = curr->prev;
                }
                if (curr->prev != nullptr){
                    curr->prev->next = curr->next;
                }
                delete curr;
            }
            length--;
        }
};
int main(){

    LinkedList list;
    list.insert(10, 1);
    list.insert(20, 2);
    list.insert(15, 2);
    list.remove(2);
    return 0;
}