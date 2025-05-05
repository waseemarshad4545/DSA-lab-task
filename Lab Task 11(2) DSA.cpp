#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
	private:
		Node* front;
		Node* rear;
		
	public:
		Queue() {
			front = rear= nullptr;
		}
	void enqueue(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next =nullptr;
		
		if( rear == nullptr) {
			front =rear=newNode;
		}else {
			rear->next =newNode;
			rear= newNode;
		}
		cout<<value<<"enqueued." <<endl;
	}
	void dequeue() {
		if(front == nullptr){
			cout<<"Queue is empty (Underflow)" <<endl;
			return;
		}
		Node* temp =front;
		cout<< temp->data << "dequeue" <<endl;
		front = front->next;
		
		if (front == nullptr){
			rear = nullptr;
		}
		delete temp;
	}
	void display(){
		if(front == nullptr){
			cout<<"Queue is empty"<<endl;
			return;
		}
		Node* temp = front;
		cout<<"Queue elements" ;
		while (temp != nullptr) {
			cout<<temp->data <<" ";
			temp =temp->next;
		}
		cout<< endl;
	}
};

int main(){
	Queue q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();
	
	q.dequeue();
	q.display();
	
	return 0;
}