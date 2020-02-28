#include<iostream>
#include <sstream> 
#include<vector>
using namespace std;

char alpha[30];

static vector<vector<char> > all_code(string in,vector<char> &out,int n,int p,int j)
{
	static vector<vector<char> > v;
	if(p>n)
	{
		return v;
	}
	if(p==n)
	{
		out[j]='\0';
		//cout<<out<<endl;
		v.push_back(out);
		return v;
	}
	int num;
	string str =  in.substr(p,1);
	stringstream obj(str);
	obj>>num;
	
	out[j] = alpha[num];
	//cout<<out[j]<<endl;
	//cout<<endl;
	
	all_code(in,out,n,p+1,j+1);
	
	str =  in.substr(p,2);
	stringstream obj2(str);
	obj2>>num;
	
	out[j] = alpha[num];
	all_code(in,out,n,p+2,j+1);
	
	return v;
	
	
}

int main()
{
	for(int i=1;i<=26;i++)
	{
		alpha[i] = 'a'+i-1 ;
	}
	/*for(int i=0;i<26;i++)
	{
		cout<<alpha[i]<<" ";
	}*/
	
	vector<char> out(100);
	string in;
	cin>>in;
	vector<vector<char> > v;
	v = all_code(in,out,in.length(),0,0);
	cout<<"[";	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i][j]!='\0';j++)
		{
			cout<<v[i][j];
		}
		if(i+1<v.size())
		{
			cout<<", ";	
		}
		
	}
	cout<<"]";
		
}
