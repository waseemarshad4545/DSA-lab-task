#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	
	Node(int value){
		data= value;
		left = right= nullptr;
	}
};
Node* insert(Node* root, int value){
	if(root == nullptr){
		return new Node(value);
	}
	if (value < root->data){
		root ->left = insert(root->left,value);
		
	} else if (value > root->data){
		root->right = insert(root->right,value);
	}
	return root;
}
void inorderTraversal(Node* root){
	if(root != nullptr) {
		inorderTraversal(root->left);
		cout<<root->data<<" ";
		inorderTraversal(root->right);
	}
}

int main(){
	Node* root= nullptr;
	root= insert(root, 50);
	insert(root, 30);
	insert(root, 70);
	insert(root, 20);
	insert(root, 40);
	insert(root, 60);
	insert(root, 80);
	
	cout<<"InorderTraversal of BST:";
	inorderTraversal(root);
	return 0;
}