#include<iostream>
using namespace std;  

class node{
    public:
    int val;
    node *next;
    node(int v){
        val = v;
        next = NULL;
    }
};


class linkedList{
    private:
    node *head;
    int length;
     public:

    linkedList(){
        length=0;
        head=NULL;
    }
    void insert(int val, int pos){
        if (pos < 1 || pos >(length+1)){
            cout << "invalid pos !";
            return;
        }
        node *n= new node(val);
        if(pos==1){
            node* tail=head;
            if (head!=NULL){
                while (tail->next!=head){
                    tail=tail->next;
                }
                tail->next=n;
                    n->next=head;}
            else {
                        n->next=n; }
            head=n;}
        
        else
        {
        node *curr=head;
        for (int  i = 1; i < (pos-1); i++)
        {
            curr=curr->next;
        }
            n->next=curr->next;
            curr->next=n;
        }
        length++;
    }


    int get(int pos){
         if (pos < 1 || pos >(length+1)){
            cout << "invalid pos !";
            return 0;
        }
        node *curr=head;
        for (int i = 1; i < pos; i++)
        {
          curr=curr->next; 
        }
        return curr->val;
     }
     
    void remove(int pos){
        if (pos < 1 || pos >(length+1)){
            cout << "invalid pos !";
            return;
        }
        node *curr =head;
        if(pos==1)
        {
            if(head->next!=head){
                node* tail=head;
                while (tail->next!=head)
                {
                    tail=tail->next;
                }
                head=head->next;
                tail->next=head;
                
            }
            else{
                head=NULL;
            }
            
            delete curr;
        }
        else
        {
        for (int i = 1; i < (pos-1); i++)
        {
          curr=curr->next; 
        }
        node *temp=curr->next;
        curr->next=temp->next;
        delete temp;

        }
        length--;
     }


    void clear(){
        while (head!=NULL)
        {
           remove(1);
        }
    }

    int find(int val){
        if(length==0){
            cout<<" list is empty !";
            return 0;
        }
        node *curr =head;
        for (int i = 1; i <=length; i++)
        {
            if (curr->val==val){
                return i;
            }
               curr=curr->next;
        }
      
            return 0;
        
    }
   
   
void josephus(int skip){
     node* curr=head;
      node* curr2 = head; 
    while(length > 1){  
        for(int i=1;i<=skip;i++) {
            curr2 = curr;
            curr = curr->next;
        }
        
        cout<<"Remove value  : "<<curr->val<<endl;
        curr2->next=curr->next;
 
        if(curr==head) {
            head=curr->next;
        }
        
        node* temp=curr;
        curr = curr->next;                 
        delete temp;
        length--;
    }
    head->next = NULL;
    
    cout<<"The selected number is: "<<head->val<<endl;
}
    ~linkedList(){
        clear();
    }
    

    void display(){
        for (int i = 1; i < length+1; i++)
        {
            cout<<get(i)<<endl;  }
    }

};

int main(){
    linkedList l,l1;
    l.insert(1,1);
    l.insert(2,2);
    l.insert(3,3);
    l.insert(4,4);
    l.insert(5,5);
    l.insert(6,6);
    l.insert(7,7);
    l.insert(8,8);
    l.insert(9,9);  
    l.insert(10,10);
    l.display();
    
    l.josephus(3);
 

}