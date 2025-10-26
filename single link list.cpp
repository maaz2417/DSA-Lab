#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *next;
		node(int val){
			this->val=val;
			next=nullptr;
		}
};
class linkedlist{
	private:
		node *head;
		int length;
	public:
		linkedlist(){
			head=nullptr;
			length=0;
		}
	void insert(int val, int pos){
		if(pos<1 || pos>length+1){
			cout<<"invalid position"<<endl;
			return;
		}
		node *n=new node(val);
		if(pos == 1 ){
			n->next=head;
			head=n;
				}
		else{
			node *curr = head;
			 for(int i = 1;i<(pos-1);i++){
			 	curr=curr->next;}
			 	n->next=curr->next;
			 	curr->next=n;
				}
				length++;
	}
	int get(int pos){
		if(pos<1 || pos>length){
			cout<<"invalid position"<<endl;
			return 0;
		}
		node *curr=head;
		for ( int i=1;i<pos;i++){
			curr=curr->next;
			}
			return curr->val;
	}
	
	void display(){
		node *curr=head;
		for(int i=1;i<=length;i++){
			cout << curr->val << "  ";
			curr=curr->next;
		}
	}
	void remove(int pos){
		if(pos<1 || pos>length+1){
			cout<<"invalid position"<<endl;
			return;
		}
		node *curr=head;
		if(pos==1){
			head=head->next;
			delete curr;
		}
		else{
		for(int i=1;i<pos-1;i++){
			curr=curr->next;
		}
		node *temp=curr->next;
		curr->next=temp->next;
		delete temp;
	}
	length--;
}
	void update(int val,int pos){
		if(pos<1 || pos>length+1){
			cout<<"invalid position"<<endl;
			return;
		}
		node *curr=head;
		for(int i=1;i<pos;i++){
			curr=curr->next;
		}
		curr->val=val;
	}
	void clear(){
		while(head!=nullptr){
			remove(1);
		}
	}
	void find(int val){
		node *curr=head;
		for(int i=1;i<=length;i++){
			if(curr->val==val){
				cout<<"Value found at position : "<<i;
				return;
			}
			else{
				curr=curr->next;
			}
		}
		cout<<"the value not found"<<endl;
	}
};
int main(){
	linkedlist l1;
	l1.insert(5,1);
	l1.insert(3,2);
	l1.insert(4,3);
	l1.insert(9,4);
	l1.insert(7,5);
	l1.display();
	cout<<endl;
	l1.remove(3);
	l1.update(69,3);
	l1.display();
	cout<<endl;
	l1.find(89);
}