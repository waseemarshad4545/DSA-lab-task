#include<iostream>
using namespace std;
int findMax(int arr[], int n){
	int maxVal = arr[0];
	for (int i=1;i<n;i++){
		if (arr[i] > maxVal){
		maxVal=arr[i];
		
	}
}
return maxVal;
}
int main(){
	int arr[]={3,8,1,7,2,9,5};
	int n=sizeof(arr) / sizeof(arr[0]);
	cout<<"Maximum value "<<findMax(arr,n)<<endl;
	return 0;
}