#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
};
void insert(Node*& head, int val){
	Node* newNode=new Node(val);
	if(!head){
		head= newNode;
		return;
	}
	Node* temp = head;
	while (temp->next){
		temp= temp->next;
	}
	temp->next =newNode;
}
	void display(Node* head) {
		while (head){
			cout<<head->data <<"->";
			head =head->next;
		}
		cout<<"NULL"<<endl;
	}
	Node* mergeLists(Node* head1,Node* head2){
		if(!head1) return head2;
		if(!head2) return head1;
		
		Node* mergedHead =NULL;
		
		if(head1->data < head2->data){
			mergedHead = head1;
			mergedHead->next= mergeLists(head1->next,head2);
		}else {
			mergedHead = head2;
			mergedHead->next= mergeLists(head1,head2->next);
		}
		return mergedHead;

}

int main(){
	Node* head1 =NULL;
	Node* head2 =NULL;
	
	insert(head1, 1);
	insert(head1, 3);
	insert(head1, 5);
	
	insert(head2, 2);
	insert(head2, 4);
	insert(head2, 6);
	cout<<"List 1";
	display(head1);
	cout<<"list 2";
	display(head2);
	
	Node* mergedHead = mergeLists(head1,head2);
	cout<<"Merged List";
	display(mergedHead);
	return 0;
}