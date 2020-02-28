#include<bits/stdc++.h>
using namespace std;
int memo[10000]={0};

int solve(int n,int &x,int &y,int &z)
{
	//cout<<n<<"  ";
	if(n==1) return memo[1]=0;
	
	int q1=INT_MAX, q2=INT_MAX;
	if(n%2==0){
		if(memo[n/2]!=0)q1= memo[n/2];
		else
		q1=solve(n/2,x,y,z)+x;
		//cout<<" q1 "<<q1<<endl;
		
	}
	else{
		if(memo[(n+1)/2]!=0)q2= memo[(n+1)/2];
		else
		q2=solve((n+1)/2,x,y,z)+x+z;
		//cout<<" q2 "<<q2<<endl;
	}
	int q3;
	if(memo[n-1]!=0) q3 = memo[n-1];
	else
	 q3=solve(n-1,x,y,z)+ y;
	//cout<<" q3 "<<q3<<endl;
	
	return min(q1,min(q2,q3));
		
	
}

int main()
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	
	cout<<solve(n,x,y,z);
	
	return 0;
}
