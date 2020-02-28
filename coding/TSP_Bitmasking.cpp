#include<iostream>

using namespace std;

int n=4;
int dist[10][10] = {
        		{0,20,42,25},
       			{20,0,30,34},
        		{42,30,0,10},
        		{25,34,10,0}
			};
			
int VISITED_ALL = (1<<n) -1;

int dp[16][4];



int tsp(int mask,int pos)
{
	
	if(mask==VISITED_ALL)
	{
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1) 
		return dp[mask][pos];
	int ans =INT_MAX;
	for(int city =0;city<n;city++)
	{
		if((mask&1<<city)==0)
		{
			cout<<(mask|1<<city)<<" city : "<<city<<" ";
			int newans = dist[pos][city] + tsp(mask|1<<city,city);
			ans =min(ans,newans);
		}
	}
	
	return dp[mask][pos]=ans;
}

int main()
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp[i][j]=-1;
		}
	}
	int ans = tsp(1,0);
	cout<<endl;
	cout<<"distance : "<<ans<<endl;
	return 0;
}
