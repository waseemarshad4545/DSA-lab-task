#include<iostream>
using namespace std;
class Node {
	public:
		int data;
		Node* next;
		Node(int value){
			data=value;
			next=nullptr;
		}
};
class SinglyLinkedList{
	private:
		Node* head;
	public:
		SinglyLinkedList(){
			head= nullptr;
		}
		void insertAtStart(int value){
			Node* newNode =new Node(value);
			
			newNode->next =head;
			head = newNode;
		}
		void insertAtEnd(int value){
			Node* newNode = new Node(value);
			if (head ==nullptr){
				head = newNode;
				return;
			}
			Node* temp =head;
			while (temp->next !=nullptr){
				temp=temp->next;
			}
			temp->next= newNode;
		}
		void display(){
			Node* temp=head;
			while (temp !=nullptr){
				cout<<temp->data <<" -> ";
				temp =temp->next;
			}
			cout<<"Null"<<endl;
		}
};

int main(){
	SinglyLinkedList list;
	
	list.insertAtEnd(10);
	list.display();
	
	list.insertAtStart(5);
	list.display();
	
	list.insertAtEnd(20);
	list.display();
	
	list.insertAtStart(1);
	list.display();
	
	return 0;
	
}