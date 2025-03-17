#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
class LinkedList {
	private:
		Node* head;
	public:
		LinkedList() {
			head = nullptr;
		}
		void insert (int value){
			Node* newNode = new Node();
			newNode->data =value;
			newNode->next = nullptr;
			
			if(head ==nullptr){
				head = newNode;
			}else {
				Node* temp = head;
				while (temp->next != nullptr){
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		void displayFirst() {
			if(head != nullptr){
				cout<<"First Node"<<head->data<<endl;
			}else {
				cout<<"List is empty!"<<endl;
			}
		}
		void displayLast() {
			if (head == nullptr) {
				cout<< "List is empty!" << endl;
				return;
			}
			Node* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			cout<<"Last Node:" <<temp->data <<endl;
			
		}
		void displayNth(int n){
			Node* temp = head;
			int count = 1;
			
			while (temp != nullptr){
				if(count == n) {
					cout <<"Node at Position" <<n<<": "<< temp->data<<endl;
				return;	
				}
				temp = temp->next;
				count++;
			}
			cout<<"Position"<<n<<"is out of range!"<<endl;
	}
			void displayMiddle(){
				if (head == nullptr){
					cout<<"List is empty!" <<endl;
					return;
				}
			Node* slow =head;
			Node* fast = head;
			while (fast != nullptr && fast->next !=nullptr){
				slow =slow->next;
				fast =fast->next->next;
			}
			cout<<"Middle Node:" <<slow->data <<endl;
			}
			void displayList(){
				Node* temp =head;
				cout<<"Linked List";
				while (temp != nullptr){
					cout<< temp->data <<"->";
					temp = temp->next;
				}
				cout<<"Null"<<endl;
			
		
		}
};

int main() {
	LinkedList list;
	
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(50);
	
	list.displayList();
	
	list.displayFirst();
	list.displayLast();
	list.displayNth(3);
    list.displayMiddle(); 
	
	return 0;
}
