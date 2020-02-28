#include<iostream>

using namespace std;

char keypad[][5]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void print_keyPad(char *in,char *out,int i,int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
	}
	
	int d = in[i]-'0';
	//cout<<"d "<<d<<endl;
	if(d==0||d==1)
	{	
		print_keyPad(in,out,i+1,j);	
	}
	

	
	else
	for(int k=0;keypad[d][k]!='\0';k++)
	{
		out[j]=keypad[d][k];
		print_keyPad(in,out,i+1,j+1);
	}
}
int main()
{
	char in[100]="2103";
	char out[100];
	//in
	print_keyPad(in,out,0,0);
	
	return 0;
}
