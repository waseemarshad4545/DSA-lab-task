#include<iostream>
using namespace std;
int main(){
	int num=10;
	int* ptr = &num;
	cout<<"before modification"<<endl;
	cout<<"value of num"<<num<<endl;
	cout<<"value at pointer ptr"<<*ptr<<endl;
	*ptr =20;
	
	cout<<"after modification"<<endl;
	cout<<"value of num"<<num<<endl;
	cout<<"value at pointer ptr"<<*ptr<<endl;
	
	return 0;
}