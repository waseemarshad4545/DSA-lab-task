#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	int height;
	
	Node(int value){
		data= value;
		left = right= nullptr;
		height =1;
	}
};

int getHeight(Node* node){
	if(node == nullptr) return 0;
	return node->height;
}

int getBalance(Node* node){
	if(node == nullptr) return 0;
	return getHeight(node->left)- getHeight(node->right);
}

Node* rightRotate(Node* y){
	Node* x = y->left;
	Node* T2 = x->right;
	
	x->right=y;
	y->left=T2;
	y->height= max(getHeight(y->left),getHeight(y->right)) +1;
	x->height= max(getHeight(x->left),getHeight(x->right)) +1;
	
	return x;
}

Node* leftRotate(Node* x){
	Node* y = x->right;
	Node* T2 = y->left;
	
	y->left=x;
	x->right=T2;
	x->height= max(getHeight(x->left),getHeight(x->right)) +1;
	x->height= max(getHeight(y->left),getHeight(y->right)) +1;
	
	return y;
	}
	Node* insert(Node* root, int value){
		if(root == nullptr)
		return new Node(value);
		
		if(value < root->data)
		root->left = insert(root->left, value);
		else if (value > root->data)
		root->right=insert(root->right, value);
		else
		    return root;
		    root->height =1+ max(getHeight(root->left),getHeight(root->right));
		int balance = getBalance(root);
		if(balance > 1 && value < root->left->data)
		return rightRotate(root);
		
		if(balance < -1 && value > root->right->data)
		return leftRotate(root);
		
		if(balance > 1 && value > root->left->data){
		root->left= leftRotate(root->left);
		return rightRotate(root);
	}

if(balance < -1 && value < root->right->data){
		root->right= rightRotate(root->right);
		return leftRotate(root);
    }
    return root;
}
void inorderTraversal(Node* root){
	if(root != nullptr) {
		inorderTraversal(root->left);
		cout<<root->data << " ";
		inorderTraversal(root->right);
    } 
}

int main(){
	Node* root=nullptr;
	root= insert(root, 30);
	root= insert(root, 20);
	root= insert(root, 40);
	root= insert(root, 10);
	root= insert(root, 25);
	root= insert(root, 35);
	root= insert(root, 50);
	
	cout<<"Inorder Traversal of AVL:";
	inorderTraversal(root);
	
	return 0;
}
	
