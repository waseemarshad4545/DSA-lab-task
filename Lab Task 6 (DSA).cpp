#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val):data(val), next(nullptr){ }
};
void insert(Node*& head , int val){
	Node* newNode = new Node(val);
	if(!head) {
		head = newNode;
		return;		
	}
	Node* temp = head;
	while (temp->next ){
		temp =temp->next;
	}
	temp->next =newNode;
}
 void display(Node* head){
 	Node* temp = head;
 	while(temp){
 		cout<<temp->data <<" ->";
 		temp = temp->next;
	 }
	 cout<<"NULL\n";
 }
 void deleteFirst(Node*& head){
 	if(!head) return;
 	Node* temp=head;
 	head = head->next;
 	delete temp;
 }
 void deleteLast(Node*& head){
 	if(!head) return;
 	if(!head->next){
 		delete head;
 		head= nullptr;
 		return;
	 }
	 Node* temp =head;
	 while (temp->next->next){
	 	temp= temp->next;
	 }
	 delete temp->next;
	 temp->next=nullptr;
}
void deleteNth(Node*& head, int n){
	if(!head) return;
	if (n == 1){
		deleteFirst(head);
		return;
	}
	Node* temp =head;
	for(int i=1; temp && i<n-1;i++){
		temp = temp->next;
	}
	if (!temp || !temp->next) return;
	Node* toDelete = temp->next;
	temp->next = temp->next->next;
	delete toDelete;
}
void deleteMiddle(Node*& head){
	if (!head || !head->next){
		delete head;
		head = nullptr;
		return;
	}
	Node* slow =head, *fast =head, *prev =nullptr;
	while (fast && fast->next){
		prev =slow;
		slow=slow->next;
		fast=fast->next->next;
	}
    prev->next =slow->next;
    delete slow;
}

int main(){
	Node* head =nullptr;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	insert(head,5);
	
	cout<<"Original List";
	display(head);
	
	deleteFirst(head);
	cout<<"After deleting first node";
	display (head);
	
	deleteLast(head);
	cout<<"After deleting Last node";
	display (head);
	
	deleteNth(head , 2);
	cout<<"After deleting 2nd node";
	display (head);
	
	deleteMiddle(head);
	cout<<"After deleting Middle node";
	display (head);
	return 0;
}