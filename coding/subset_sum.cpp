#include<iostream>
#include<vector>

using namespace std;

void subset_sum(vector<int> &set,vector<bool> &ex,int sum,int m,int i,int j)
{
	if(sum<m || i>j)
	{
		return ;
	}
	if(sum == m)
	{
		for(int k=0;k<j;k++)
		{
			if(ex[k])
			cout<<set[k]<<" ";
		}
		cout<<endl;
		return ;
	}

	subset_sum(set,ex,sum,m,i+1,j);
	m += set[i];
	ex[i]=1;
	subset_sum(set,ex,sum,m,i+1,j);
	ex[i]=0;
	
}


int main()
{
	int n,e,s;
	vector<int> set;
	
	cout<<"Enter no. of elements in set : ";
	cin>>n;
	for(int i=0; i<n;i++)
	{
		cin>>e;
		set.push_back(e);
	}
	vector<bool> ex(n,0);
	cout<<"enter SuM : ";
	cin>>s;
	subset_sum(set,ex,s,0,0,n);
	
}

