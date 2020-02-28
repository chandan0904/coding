#include<iostream>

using namespace std;

void print(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int *createArray()
{
	int a[]= {1,2,3,4,5};
	/*int *a= new int[5];
	for(int i=0;i<5;i++)
	{
		a[i]=i*i;
	}*/
	print(a,5);
	cout<<"a = "<<a<<endl;
	return a;
}

void space(int n)
{
	while(n--)
	{
		int *a = new int[n];
		cout<<a<<endl;
	}
}

int main()
{
	space(10);
	/*int *b= createArray();
	cout<<"b = "<<b<<endl;
	print(b,5);*/
}
