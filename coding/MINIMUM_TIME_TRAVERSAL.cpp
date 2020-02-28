#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long int ans = 1e16;

void findPath(vector<int> s,vector<int> e,vector<vector<int> > h,
				vector<bool> f,bool d,int a,int n,long long int time)
{
	if(d)
	{
		int t = abs(s[0]-e[0])+abs(s[1]-e[1]);
		ans = min(ans,t+time);
		return ;
	}
	if(a==n)
	{
		int t = abs(s[0]-e[0])+abs(s[1]-e[1]);
		ans = min(ans,t+time);
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!f[i])
		{
			f[i]=true;
			
			long int t= abs(s[0]-h[i][0])+abs(s[1]-h[i][1]) +h[i][4];
			int sx = s[0];
			int sy = s[1];
			s[0]=h[i][2];
			s[1]=h[i][3];
			
			findPath(s,e,h,f,d,a+1,n,time+t);
			s[0] = sx;
			s[1] = sy;
			f[i] = false;
			
			t= abs(s[0]-h[i][2])+abs(s[1]-h[i][3]) +h[i][4];
			sx = s[0];
			sy = s[1];
			s[0]=h[i][0];
			s[1]=h[i][1];
			
			findPath(s,e,h,f,d,a+1,n,time+t);
			s[0] = sx;
			s[1] = sy;
			f[i] = false;
			
			
		}
	}
	findPath(s,e,h,f,!d,a+1,n,time);
}
int main()
{
	int t;
	cin>>t;
	int q=1;
	while(t--)
	{
		int n;
		
		vector<int> s(2);
		vector<int> e(2);
		
		cin>>n;
		cin>>s[0]>>s[1];
		cin>>e[0]>>e[1];
		vector<vector<int> > h(n,vector<int>(5));
		vector<bool> f(n);
		
		ans = 1e16;
		for(int i=0;i<n;i++)
		{
			cin>>h[i][0];
			cin>>h[i][1];
			cin>>h[i][2];
			cin>>h[i][3];
			cin>>h[i][4];
			f[i]=false;
		}
		findPath(s,e,h,f,false,0,n,0);
		cout<<"#"<<q<<" : "<<ans<<endl;
		q++;
	}
	
	return 0;
}


