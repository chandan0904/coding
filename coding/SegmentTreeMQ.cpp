#include<iostream>
#include<vector>
#include<cmath>
#include<windows.h>
using namespace std;

void constructTree(vector<int> &input,vector<int> &segtree,int low,int high,int pos)
{
	if(low==high)
	{
		segtree[pos] = input[low] ;
		//cout<<segtree[pos]<<" ";
		return ;
	}
	 //Sleep(500);
	int mid = (low+high)/2;
	
	constructTree(input,segtree,low,mid,2*pos+1);
	constructTree(input,segtree,mid+1,high,2*pos+2);
	segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
	//cout<<segtree[pos]<<" ";
	
}

int minimumQuery(vector<int> &segtree,int low,int high,int ql,int qh,int pos)
{
	if(low>=ql && high<=qh)
	{ 
		return segtree[pos];
	}
	
	if(low>qh || high <ql)
	{
		return INT_MAX;
	}
	int mid = (low+high)/2;
	return min( minimumQuery(segtree,low,mid,ql,qh,2*pos+1) , minimumQuery(segtree,mid+1,high,ql,qh,2*pos+2) );
}

int main()
{
	int a,b,n,q;
	vector<int> input;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		input.push_back(a);
	}
	/*for(int i=0; i<input.size();i++)
	{
		cout<<input[i]<<" ";
	}*/
	cout<<endl;
	vector<int> segtree(n*2-1,-20);
	/*for(int i=0; i<segtree.size();i++)
	{
		cout<<segtree[i]<<" ";
	}*/
	cout<<endl;
	constructTree(input,segtree,0,n-1,0);
	for(int i=0; i<segtree.size();i++)
	{
		cout<<segtree[i]<<" ";
	}
	
	cout<<endl;
	for(int i=0; i<q; i++)
	{
		cin>>a;
		cin>>b;
		cout<<"output : "<<minimumQuery(segtree,0,n-1,a,b,0)<<endl; 
	}
	
	return 0;
	
}
