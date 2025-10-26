#include <iostream>
using namespace std;


class ArrayList{
    private:
        int *arr;
        int capacity;
        int length; //no of items;
        int *curr;
    public:
        ArrayList(int s) {
            arr = new int[s];
            capacity = s;
            length = 0;
            curr = NULL;
        }
        ~ArrayList() {
            delete[] arr;
        }
        void start() {
            curr = arr;
        }
        void next () {
            curr++;
        }
        void back() {
            curr--;
        }
        void end() {
            curr = arr + length - 1;
        }
        void insert(int val, int pos) {
            if (length == capacity) {
                cout << "FULL" << endl;
                return;
            }
            if (pos < 1 || pos > (length +1)){
                cout << "Invalid Position" << endl;
                return;
            }
            end();
            for (int i = length; i >= pos; i--) {
                *(curr +1) = *curr;
                back();
            }
            *(curr+1) = val;
            length++;
        }
        void remove(int pos){
            if (length == 0) {
                cout << "EMPTY" << endl;
                return;
            }
            if (pos < 1 || pos > length) {
                cout << "Invalid Position" << endl;
                return;
            }
            start();
            for (int i = 1; i < pos; i++) {
                next();
            }
            for (int i = pos; i < length; i++) {
                *curr = *(curr + 1);
                next();
            }
            length--;
        }
        int get(int pos){
            if (length == 0) {
                cout << "EMPTY" << endl;
                return -1;
            }
            if (pos < 1 || pos > length) {
                cout << "Invalid Position" << endl;
                return -1;
            }
            start();
            for (int i = 1; i < pos; i++) {
                next();
            }
            return *curr;
        }
        void update(int val, int pos){
            if (pos < 1 || pos > length) {
                cout << "Invalid Position" << endl;
                return;
            }
            curr = arr + pos - 1;
            *curr = val;
        }
        int getLength() {
            return length;
        }
        void clear() {
            length = 0;
        }
};


int main() {
    ArrayList list(5);
    list.insert(10,1);
    list.insert(20,2);
    list.insert(30,3);
    list.insert(40,4);
    list.insert(50,5);
    cout << "Element at position 3: " << list.get(3) << endl;
    list.update(35,3);
    cout << "Updated element at position 3: " << list.get(3) << endl;
    list.remove(2);
    cout << "Element at position 2 after removal: " << list.get(2) << endl;
    cout << "Current length of the list: " << list.getLength() << endl;
    list.clear();
    cout << "Length after clearing the list: " << list.getLength() << endl;
    return 0;
}