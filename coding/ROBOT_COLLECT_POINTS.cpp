#include<iostream>
#include<vector>

using namespace std;
#define s(x) scanf("%d",&x)
#define p(x) printf("%d\n",x)
#define v vector<int>
#define vv vector<v>

vv grid(15,v(15)),dp(15,v(15)), b(15,v(15));
int h,w=5;

void copy(int k)
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<5;j++)
		{
			b[i][j]=grid[i][j];
			dp[i][j]=-1e5;
		}
	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(b[i+k][j]==-1)
				b[i+k][j]=0;
				
		}
		
	}
}


int  collecte(int i,int j)
{
	int count=0;
	if(i>=0 && j>=0 && j<5 )
	{
		
		if(dp[i][j]!=-1e5) return dp[i][j];
		
		count = b[i][j];
		
		int scor = INT_MIN; 
		scor = max(scor,collecte(i-1,j+1));
		scor = max(scor,collecte(i-1,j-1));
		scor = max(scor,collecte(i-1,j));
		count += scor;
		//cout<<count<<endl;
		dp[i][j]=count;
	}
	return count;
	
}

int main()
{
	int t;
	s(t);
	while(t--)
	{
		
		s(h);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<5;j++)
			{
				s(grid[i][j]);
			}
		}	
		
		int ans=-1e5;
		for(int i=0;i<h-4;i++)
		{
			copy(i);
			//cout<<"hrer";
			ans = max(ans,collecte(h-1,2));
			ans = max(ans,collecte(h-1,3));
			ans = max(ans,collecte(h-1,1));
		}
		p(ans);
		
	}
	
	
	return 0;
}
