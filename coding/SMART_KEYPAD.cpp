#include<iostream>
#include<string>
using namespace std;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    	};

string phoneKey[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void smart_keypad(string inn,char *out,int p,int j)
{
	if(inn[p]=='\0')
	{
		out[j]='\0';
		for(string s :searchIn)
		{
			if(s.find(out)!=string::npos){
				cout<<s<<endl;
			}
		}
		//cout<<"gr"<<endl;
		return;
	}

	int d = inn[p]-'0';
	if(d==0 || d==1)
		smart_keypad(inn,out,p+1,j);
	else
	{
		for(int i=0;phoneKey[d][i]!='\0';i++)
		{
			out[j]=phoneKey[d][i];
			smart_keypad(inn,out,p+1,j+1);
		}
	}
}

int main() {
	string in;
	cin>;>in;
	char out[15];
	//cout<<"wugiug"<<endl;
	smart_keypad(in,out,0,0);
	return 0;
}
