#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

#define ll long long int
#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define p(x) printf("%lld\n",x)
#define F(i,in,r) for(ll i=(ll)in;i< (ll)r;i++)
#define ff first
#define ss second
#define mkp(x,y) make_pair(x,y)


ll n,m;
ll dfs(vector<vector<ll>> &mat,ll r,ll c,ll &gid)
{
	 mat[r][c]=gid;
	 ll k=1;
	 if(r+1<n && mat[r+1][c]==1) k+=dfs(mat,r+1,c,gid);
	 if(r-1>=0 && mat[r-1][c]==1) k+=dfs(mat,r-1,c,gid);
	 if(c+1<n && mat[r][c+1]==1) k+=dfs(mat,r,c+1,gid);
	 if(c-1>=0 && mat[r][c-1]==1) k+=dfs(mat,r,c,gid);
	 
	 return k;
}

int main()
{
	
	s2(n,m);
	vector<vector<ll> >  mat(n,vector<ll>(m));
	F(i,0,n)
	{
		F(j,0,m)
		{
			cin>>mat[i][j];
		}
	}
	
	
	map<ll,ll> mp;
	ll gid=2;
	ll ans= - 1e10;
	
	F(i,0,n)
	{
		F(j,0,m)
		{
			if(mat[i][j]==1)
			{
				//cout<<i<<" "<<j<<endl;
				mp[gid] = dfs(mat,i,j,gid);
				ans = max(ans,mp[gid]);
				gid++;	
			}	
		}
	}
	
	F(i,0,n)
	{
		F(j,0,m)
		{
			if(mat[i][j]==0)
			{
				set<ll> st;
				
				if(i-1>=0 && mat[i-1][j]>1) st.insert(mat[i-1][j]);
				if(i+1<n && mat[i+1][j]>1)  st.insert(mat[i+1][j]);
				if(j-1>=0 && mat[i][j-1]>1) st.insert(mat[i][j-1]);
				if(j+1<m && mat[i][j+1]>1)  st.insert(mat[i][j+1]);
				
				ll count =1;
				for(ll id : st)
				{
					count += mp[id];
				}
				ans = max(ans,count);
			}
		}
		
	}
	p(ans);
	/*for(pair<int,int> p:mp)
	{
		cout<<p.second<<endl;
	}*/
	return 0;
}
