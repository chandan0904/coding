#include<iostream>

using namespace std;
int m,n,u=-1;
int l[20]={0},r[20]={0};
int fun(int f,int p)
{
	
	int ans = INT_MAX;
	if(f)
	{
		if(p==u-1)
			return r[p];
			
		ans = min( ans, fun(0,p+1) + m+2);
		//cout<<"t p "<<p<<" ans "<< ans<<endl;
		ans = min( ans, fun(1,p+1) + 2*r[p]+1);
		//cout<<"t p "<<p<<" ans "<< ans<<endl;
	}
	else
	{
		if(p==u-1)
			return l[p];
			
		ans = min( ans, fun(0,p+1) + 2*l[p]+1 );
		//cout<<"f p "<<p<<" ans "<< ans<<endl;
		ans = min( ans, fun(1,p+1) + m + 2 );
		//cout<<"f p "<<p<<" ans "<< ans<<endl;
		
	}
	return ans;	
	
}


int main()
{
	
	cin>>n>>m;
	
	string b[n];
	for(int i=n-1;i>=0;i--)
	{
		cin>>b[i];
	}
	
	
	int temp=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<b[i].length();j++)
		{
			if(b[i][j]=='1')
			{
				
				l[i]=max(l[i],j);
				
				r[i] = max(r[i],m+1-j);	
			}/*
			if(b[i][j]=='1')
			l[i]=max(j,l[i]);
			if(b[i][m+1-j]=='1')
			r[i]=max(r[i],j);*/
		}
		if(l[i])
			temp = i;
	}
	
	/*for(int i=0;i<n;i++)
	{
		cout<<l[i]<<"  "<<r[i]<<endl;
	}
	*/
	u = temp+1;
	
	if(u==0)
	{
		cout<<0<<endl;
		return 0;
	}
	if(u== 1)
	{
		cout<<l[0]<<endl;
		return 0;
	}
	int ans = INT_MAX;
	ans = min( ans, fun(0,1) + 2*l[0]+1);
	//cout<<"ans "<<ans<<endl;
	ans = min( ans, fun(1,1) + m+2);
	//cout<<"ans"<<ans<<endl;
	cout<<ans<<endl;
	
	
	return 0;
}
