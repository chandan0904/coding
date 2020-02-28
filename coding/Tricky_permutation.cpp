#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> permutation(string in,int p)
{
	static vector<string> v;
	if(in[p]=='\0')
	{
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==in)
			{
				return v;
			}
			
		}
		v.push_back(in);
		for(int i=v.size()-1;i>0;i--)
		{
			if(v[i]<v[i-1])
			{
				swap(v[i],v[i-1]);
			}
			else
				return v;
		}
		return v;
	}
	
	for(int i=p;in[i]!='\0';i++)
	{
		if(in[p]!=in[i])
		{	
			swap(in[p],in[i]);
			//cout<<"1  "<<in<<endl;
			permutation(in,p+1);
			//cout<<"in["<<p<<"] ="<<in[p]<<"in["<<i<<"] = "<<in[i]<<"  swap "<<in<<endl;
			swap(in[p],in[i]);
			//cout<<"2  "<<in<<endl;
			//cout<<in<<endl;
		}
		
		if(p==i)
		{
			
			//cout<<in<<endl;
			permutation(in,p+1);
		}
		     
		
	}
	return v;
}

int main()
{
	string in;
	cin>>in;
	cout<<endl;
	char out[10];
	vector<string> v = permutation(in,0);
	//cout<<"fbnbvfghjsdfgjasdfghgfdfg"<<endl;
	//sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}
