#include<iostream>

using namespace std;

void fun(long int mask,long int &a,int k,long int &ans)
{
	if(k<2)
		return ;
	
	
		//cout<<"here1 "<<k<<endl;
		fun(mask,a,k-2,ans);
		
		//cout<<"here2 "<<k<<endl;	
			
		mask =mask+(1<<(k-1));
		//cout<<" mask "<<mask<<endl;
		if(mask>a && ans<a){
			ans = mask;
			//cout<<"knsg"<<endl;
			return ; 
		}
		
		fun(mask,a,k-2,ans);
			
		mask =mask-(1<<(k-1));

	return ; 
	
}

int main()
{
	/*long int t = 41;
	long int m,ans;
	ans=0;
	m = 1<<5;
	fun(m,t,5-1,ans);
	cout<<ans;*/
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long int v[n];
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			
		}
		
		for(int i=0;i<n;i++)
		{
			if(v[i]==-1)
			{
				int k=0;
				int p = v[i-1];
				while(p>0)
				{
					p = p>>1;
					k++;
				}
				if(k&1)
				{
					v[i] = 1<<k;
					continue;
				}
				long int mask=0;
				int l=2;
				while(l<=k)
				{  
					mask= mask+(1<<(l-1));
					l+=2;
				}
				//cout<<"here "<<mask<<endl;
				if(mask<v[i-1])
				{
					//cout<<1<<endl;
					v[i]=1<<(k+1);
					continue;
				}
				if(mask==v[i-1])
				{
					//cout<<2<<endl;
					v[i]=mask;
					continue;
				}
				long int  ans=0;
				//cout<<3<<endl;
				mask = 1<<(k-1);
				fun(mask,v[i-1],k-2,ans);
				v[i]= ans;
			}
			
		}
		long long int sum=0;
		for(int i=0;i<n;i++)
		{
				cout<<v[i]<<" ";
				sum += v[i];
		}
		
		cout<<endl;
		cout<<sum<<endl;
		
	}
	
	return 0;
}

