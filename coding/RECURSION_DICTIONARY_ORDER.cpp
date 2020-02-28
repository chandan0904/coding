#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
string inp;
void permutation(string str,int p)
{
	if(str[p]=='\0')
	{
		//cout<<str<<endl;
		if(str>inp)
			v.push_back(str);
			
		return ;
	}
	
	for(int i=p ; str[i]!= '\0' ;i++)
	{
		swap(str[p],str[i]);
		//cout<<str<<endl;
		permutation(str,p+1);
		swap(str[p],str[i]);
		
	}
	//cout<<"d"<<endl;
}

int main()
{
	string str;
	cin>>str;
	inp=str;
	//int n= str.length();
	//cout<<"size of v "<<v.size()<<endl;
	permutation(str,0);
	sort(v.begin(),v.end());
	//cout<<"\nsize of v "<<v.size()<<endl;
	cout<<v[0]<<endl;

	for(int i=1;i<v.size();i++)
	{
		if(v[i-1]!=v[i])
			cout<<v[i]<<endl;
	}
	
	return 0;
}
