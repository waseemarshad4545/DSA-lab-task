#include<iostream>
using namespace std;
#define SIZE 100
class Queue {
	private:
		int arr[SIZE];
		int front, rear;
		
	public:
		Queue() {
			front =-1;
			rear =-1;
		}
		void enqueue(int value) {
			if (rear == SIZE - 1){
				cout<< "Queue is full (Overflow)" <<endl;
				return;
			}
		if (front == -1) front =0;
		
		rear++;
		arr[rear] = value;
		cout<<value<<" enqueued" <<endl;
		}
		
		void dequeue() {
			if (front == -1 || front > rear){
				cout<< "Queue is empty (Underflow)" <<endl;
				return;
			}
		cout<<arr[front] <<"dequeue" <<endl;
		front++;
		}
		
		void display() {
			if (front == -1 || front > rear){
				cout<< "Queue is empty" <<endl;
				return;
			}
		cout<<"Queue elements" ;
		for (int i=front; i<=rear; i++){
			cout<<arr[i]<<" ";
		}
		cout<< endl;
	}
};

int main() {
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();
	
	q.dequeue();
	q.display();
	return 0;
}