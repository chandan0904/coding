#include<iostream>
#include<vector>
#include<cstring>
#define ll long long 
using namespace std;

ll p;
int k;

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B)
{
	vector<vector<ll> > c(k+2,vector<ll>(k+2,0));
	for(int i=1;i<=k+1;i++)
	{
		for(int j=1;j<=k+1;j++)
		{
			for(int l=1;l<=k+1;l++)
			{
				
				c[i][j] = (c[i][j]+ (A[i][l]*B[l][j])%p)%p;
			}
		}
	}
	return c;
}

vector<vector<ll> > pow(vector<vector<ll> > T,ll n)
{
	//cout<<"here "<<n<<endl;
	if(n==1)
		return T;
	
	vector<vector<ll> > X = pow(T,n/2);
	X = multiply(X,X);
	
	if(n&1)
	{
		X = multiply(X,T);
	}
	return X;
}


ll getNthSum(vector<vector<ll> > T,vector<ll> b, ll n)
{
	
	//cout<<"n "<<n<<endl;
	ll ans =0;
	if(n<=k)
	{
		//cout<<"hh "<<n<<endl;
		for(int i=1;i<=n+1;i++)
		{
			ans = (ans+ b[i]%p)%p;
		}
		return ans;
	}
	//cout<<"kkk"<<endl;
	vector<vector<ll> > res = pow(T,n);
	
	for(int i=1;i<=k+1;i++)
	{
		ans = (ans+ (res[1][i]*b[i])%p)%p;
	}
	return ans;
}

int main()
{
	int t;
	ll m,n;
	cin>>t;
	vector<ll> b(18);
	vector<ll> c(18);
	vector<vector<ll> > T(18,vector<ll>(18));
	while(t--)
	{
		cin>>k;
		b[1] =0;
		for(int i=2;i<=k+1;i++)
		{
			cin>>b[i];
		}
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
		}
		
		/*for(int i=1;i<=k;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=k;i++)
		{
			cout<<c[i]<<" ";
		}*/
		//cout<<endl;
		/*memset(T,0;sizeof(T));
		T[1][1] = 1;
		for(int i=2;i<=k;i++)
		{
			T[i-1][i]=1;
		}
		*/
		
		for(int i=1;i<=k+1;i++)
		{
			for(int j=1;j<=k+1;j++)
			{
				if(i<=k)
				{
					if(i+1 == j)
					{
						T[i][j] = 1;
						
					}
					else
					{
						T[i][j] = 0;
					}
					continue;
				}
				if(j!=1)
				T[i][j] = c[k-j+2];
			}
		}
		T[1][1]=1;
		/*for(int i=1;i<=k+1;i++)
		{
			for(int j=1;j<=k+1;j++)
			{
				cout<<T[i][j]<<" ";
			}
			cout<<endl;
		}*/
		cin>>m>>n>>p;
		if(n<=k)
		{
			ll l=0,r =0;
			for(int i=1;i<m;i++)
			{
				l = (l+ b[i]%p)%p;
			}
			for(int i=1;i<=n;i++)
			{
				r = (r+ b[i]%p)%p;
			}
			ll ans = (r -l+p)%p;
			cout<<ans<<endl;
			
		}
		
		ll l= getNthSum(T,b,m-1);
		ll r = getNthSum(T,b,n);
		ll ans = (r -l+p)%p;	
		cout<<ans<<endl;	
	}
	return 0;
}
