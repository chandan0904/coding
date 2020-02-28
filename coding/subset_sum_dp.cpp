#include<iostream>
#include<vector>

using namespace std;

void subset_sum(vector<vector<bool> > &dp,vector<int> &set,int n,int sum)
{
	for(int i=0;i<n+1;i++)
		dp[i][0]=1;
	for(int j=1;j<sum+1;j++)
	dp[0][j]=0;
	
	for(int i=1;i<n+1;i++)
	{
		cout<<"uuuu"<<endl;
		for(int j=1;j<sum+1;j++)
		{
			cout<<"hh"<<endl;
			if(set[i-1]>j)
			{
				dp[i][j] = dp[i-1][j];
				cout<<"iii"<<endl;
			}
			else
			{
				dp[i][j] = dp[i-1][j] || (set[i-1]==j)|| dp[i-1][j-set[i-1]];
				cout<<"eee"<<endl;
			}
		}
	}

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n,e,sum;
	vector<vector<bool> > dp;
	vector<int> set;
	cout<<"Enter no. of elements in set : ";
	cin>>n;
	cout<<"Enter Sum value : ";
	cin>>sum;
	dp.resize(n+1,vector<bool>(sum+1));
	cout<<"Enter elements in set : ";
	for(int i=0;i<n;i++)
	{
		cin>>e;
		set.push_back(e);
	}
	
	subset_sum(dp,set,n,sum);
	
	
	return 0;
}
