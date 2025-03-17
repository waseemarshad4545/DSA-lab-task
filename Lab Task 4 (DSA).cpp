#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int value){
			data = value;
			next = nullptr;
		}
};
class SinglyLinkedList {
	private:
		Node* head;
	public:
		SinglyLinkedList(){
			head= nullptr;
		}
		void insertAtPosition(int value,int Position){
			Node* newNode = new Node(value);
			if(Position == 1){
				newNode->next =head;
				head = newNode;
				return;
			}
			Node* temp = head;
			int count =1;
			while (temp != nullptr) {
				cout<<"Invalid position!"<<endl;
				return;
			}
			newNode->next =temp->next;
			temp->next = newNode;
		}
		void display(){
			Node* temp = head;
			while (temp != nullptr){
				cout<< temp->data<<"->";
				temp = temp->next;
			}
			cout <<"Null"<<endl;
		}
};

int main(){
	SinglyLinkedList list;
	
	list.insertAtPosition(10,1);
	list.display();
	
    list.insertAtPosition(20,2);
	list.display();
	
	list.insertAtPosition(5,1);
	list.display();	
	
	list.insertAtPosition(15,3);
	list.display();
	
	list.insertAtPosition(30,10);
	return 0;
}