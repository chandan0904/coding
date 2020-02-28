#include<bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin>>q;
	
	while(q--)
	{
		string s,t,p;
		cin>>s>>t>>p;
		
		int alp[28];
		memset(alp,0,sizeof(alp));
		
		int a;
		for(int i=0;p[i]!='\0';i++)
		{
			a = p[i] -'a';
			alp[a]++;
		}
		/*for(int i=0;i<28;i++)
		{
			cout<<alp[i]<<" ";
		}
		cout<<endl;*/
		bool f= true;
		int i=0,j=0;
		int count = 0;
		while(t[j]!='\0')
		{
			if(s[i]==t[j])
			{
				i++,j++;
			}
			else
			{
				a = t[j]-'a';
				if(alp[a]!=0)
				{
					alp[a]--;
					//count++;
				}
				else
				{
					f=false;
					//cout<<"hereh "<<i<<" "<<j<<endl;
					break;
				}
				j++;
			}
			
		}
		if(s[i]=='\0' && f)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
		
	}
}
