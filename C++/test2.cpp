#include<iostream>
using namespace std;
int hack(int arr[],int n){
	int res=0,i;
	for(i=0;i<n;i++)
	{
		res^=arr[i];
	}
	return res;
}

int main(void)
{
	int arr[]={22,22,24,90,24,24,24};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<hack(arr,n);
	return 0;
}