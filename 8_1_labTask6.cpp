#include <iostream>
#include <string>
using namespace std;

class Page {
public:
    string url;
    Page* next;
    Page* prev;
    Page(const string& url) : url(url), next(nullptr), prev(nullptr) {}
};

class LinkedPages {
private:
    Page* head;
    Page* tail;
    Page* current;
    int length;

    void clearForward(Page* node) {
        Page* iter = node;
        while (iter) {
            Page* tmp = iter;
            iter = iter->next;
            delete tmp;
            length--;
        }
    }

public:
    LinkedPages() : head(nullptr), tail(nullptr), current(nullptr), length(0) {}

    ~LinkedPages() {
        Page* iter = head;
        while (iter) {
            Page* tmp = iter;
            iter = iter->next;
            delete tmp;
        }
    }

    void visit(const string& url) {
        Page* n = new Page(url);
        if (head == nullptr) {
            head = tail = current = n;
            length = 1;
            return;
        }
        if (current->next) {
            clearForward(current->next);
            current->next = nullptr;
            tail = current;
        }
        current->next = n;
        n->prev = current;
        tail = n;
        current = n;
        length++;
    }

    void goNext() {
        if (current && current->next) current = current->next;
    }

    void goPrev() {
        if (current && current->prev) current = current->prev;
    }

    void display() {
        Page* iter = head;
        while (iter) {
            cout << iter->url << endl;
            iter = iter->next;
        }
    }

    void displayCurrent() {
        if (current) cout << "Current: " << current->url << endl;
        else cout << "No current page\n";
    }

    int size() const { return length; }
};

int main() {
    LinkedPages a;
    a.visit("www.youtube.com");
    a.visit("www.github.com");
    a.visit("www.google.com");
    a.display();
    a.displayCurrent();
    a.goPrev();
    a.displayCurrent();
    a.visit("www.stackoverflow.com");
    a.display();
    a.displayCurrent();
    return 0;
}
