#include<iostream>
using namespace std;
#define  Max 5
class Stack {
	int top;
  int arr[MAX];
public:
		Stack(){top= -1;}
	void push(int value){
		if(top >= MAX - 1){
			cout<<"Stack Over flow! cannot push"<<value<<endl;
			
		}else{
			arr[++top] =value;
			cout<< value << "pushed into stack\n";
		}
	}
	void pop() {
		if(top < 0){
			cout<<"Stack Underflow! No elements to pop";
		}else{
			cout<< arr[top--] << "popped from stack";
		}
	}
	void display(){
		if (top < 0){
			cout<<"Stack is empty";
		}else{
			cout<<"Stack elements";
			for (int i=top; i>=0; i--)
			cout<<arr[i] << " ";
			cout<< endl;
		}
	}
};

int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	s.pop();
	s.display();
	return 0;
}