#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node* prev;
};
void insert(Node*& head, int data){
	Node* newNode = new Node{data, nullptr, nullptr};
	if (!head){
		head = newNode;
		return;
	}	
	Node* temp=head;
	while (temp->next){
		temp= temp->next;
	}
	temp->next =newNode;
	newNode->prev =temp;
}

void display(Node* head){
	Node* temp=head;
	while(temp){
		cout<<temp->data<<" <-> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

Node* mergeLists(Node* head1,Node* head2){
	if (!head1) return head2;
	if (!head2) return head1;
		
	Node* temp=head1;
	while (temp->next){
		temp = temp->next;
	}
	temp->next =head2;
	head2->prev =temp;
	
	return head1;
}

int main(){
	Node* head1 =nullptr;
	Node* head2 =nullptr;
	
	insert(head1,10);
	insert(head1,20);
	insert(head1,30);
	
	insert(head2,40);
	insert(head2,50);
	insert(head2,60);
	
	cout<<"First Doubly Linked List";
	display(head1);
	
	cout<<"Second Doubly Linked List";
	display(head2);
	Node* mergedHead = mergeLists(head1, head2);
	display(mergedHead);
	
	return 0;
	
}