#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
    private:
        node *head;
        int len;
    public:
        list()
        {
            head = NULL;
            len = 0;
        }

        void insert(int val, int pos) //insertion by position pos >= 1, for invalid position don't insert
        {
            if(pos < 1 || pos > (len+1))
            {
                cout<<"Invalid Position"<<endl;
                return;
            }
            
                node *n = new node(val);
            if(pos == 1) //insertion at head
            {
                n->next = head;
                head = n;
            }
            else            //insertion at other positions
            {
                node *temp = head;
                node *prev;
                while (temp != NULL && pos != 1)
                {
                    prev = temp;
                    temp = temp->next;
                    pos--;
                }
                
                prev->next = n;
                n->next = temp;
            }
            len++;
        }

        void deleteNode(int pos) //deletes nodes from a given position
        {
            if(pos < 1 || pos > (len))
            {
                cout<<"Invalid Position"<<endl;
                return;
            }

            if(head == NULL) //List is empty
                return;

            node *temp = head;

            if(pos == 1) //delete head
            {
                head = temp->next;
                delete temp;
            }
            else
            {
                for (int i = 1; i < (pos-1); i++) //stop a node before the one to be deleted
                    temp = temp->next;

                node* delptr = temp->next; //node to be deleted
                temp->next = temp->next->next;
                delete delptr;
            }
            len--; //length decreased
        }

        bool search(int val) //searches a value and return true if found and false otherwise
        {   //if anyone is returning index of the found value, consider that to be correct as well
            if(head == NULL) //list empty, node not present
                return false;
            
            node *temp = head;

            while (temp != NULL)
            {
                if(temp->data == val)
                    return true;

                temp = temp->next;
            }
            return false;
        }

        bool isEmpty()
        {
            if(head == NULL)    //can be checked using "len" as well
                return true;
            else
                return false;
        }
        
        void printList()
        {
            if (head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            
            node *temp = head;
            
            while (temp != NULL)
            {
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }      

        void swap(int p1, int p2)
        {
            if (p1 == p2 || head == NULL)
                return;

            node *first = head;
            node *pfirst = NULL;
            for (int i = 1; i < p1; i++)
            {
                pfirst = first;
                first = first->next;
            }

            node *sec = head;
            node *psec = NULL;
            for (int i = 1; i < p2; i++)
            {
                psec = sec;
                sec = sec->next;
            }

            if(pfirst != NULL)
                pfirst->next = sec;
            else
                head = sec;

            if(psec != NULL)
                psec->next = first;
            else    
                head = first;

            node *temp = sec->next;
            sec->next = first->next;
            first->next = temp;
        }

        int get(int pos)
        {
            node *curr = head;
            for (int i = 1; i < pos; i++)
                curr = curr->next;

            return curr->data;            
        }

        int length()
        {
            return len;
        }

        void reverseCopy(list l)
        {
            for (int i = 1; i <= l.length(); i++)
            {
                insert(l.get(i), 1);
            }
            
        }
};

int main()
{
    list l;
    l.insert(2, 1);
    l.insert(5, 2);
    l.insert(3, 3);
    l.insert(7, 4);
    l.printList();
    // l.swap(1, 3);
    cout<<l.get(4)<<endl;

    list l1;
    l1.reverseCopy(l);
    l1.printList();
}