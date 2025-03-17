#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	Node(int val){
		data = val;
		prev = next= nullptr;
	}
};
class doublyLinkedList {
	private:
		Node* head;
		Node* tail;
	public:
		doublyLinkedList(){
			head = tail =nullptr;
		}
		void insertAtFirst(int val){
			Node* newNode = new Node(val);
			if(!head){
				head = tail =newNode;
			}else{
				newNode->next=head;
				head->prev = newNode;
				head=newNode;
			}
		}
		void insertAtLast(int val){
			Node* newNode = new Node(val);
			if(!head){
				head = tail =newNode;
			}else{
				tail->next=newNode;
				newNode->prev = tail;
				tail=newNode;
	}
 }
        void insertAtNth(int val, int pos){
        	if(pos<=1){
        		insertAtFirst(val);
        		return;
			}
			Node* temp = head;
			for(int i=1;temp && i<pos - 1;i++){
				temp=temp->next;
			}
			if(!temp || !temp->next){
				insertAtLast(val);
				return;
			}
			Node* newNode = new Node(val);
			newNode->next = temp->next;
			newNode->prev =temp;
			temp->next->prev =newNode;
			temp->next =newNode;
		}
		void insertAtCenter(int val){
			if(!head){
				insertAtFirst(val);
				return;
			}
			Node* slow=head;
			Node* fast=head;
			
			while(fast && fast->next){
				slow =slow->next;
				fast =fast->next->next;
			}
		Node* newNode = new Node(val);
			newNode->next = slow->next;
			newNode->prev =slow;
			if(slow->next){
				slow->next->prev=newNode;
			}
			slow->next=newNode;
			if(!newNode->next){
				tail=newNode;
			}	
		}
		void displayForward(){
			Node* temp =head;
			cout<<"Forward";
			while (temp){
				cout<<temp->data<<" <-> ";
				temp=temp->next;
			}
			cout<<"NULL\n";
		}
		void displayReverse(){
			Node* temp =tail;
			cout<<"Reverse";
			while (temp){
				cout<<temp->data<<" <-> ";
				temp=temp->prev;
			}
			cout<<"NULL\n";
	}
};

int main() {
	doublyLinkedList dll;
	
	dll.insertAtFirst(10);
	dll.insertAtLast(20);
	dll.insertAtLast(30);
	dll.insertAtNth(15,2);
	dll.insertAtCenter(25);
	
	dll.displayForward();
	dll.displayReverse();
	
	return 0;
}