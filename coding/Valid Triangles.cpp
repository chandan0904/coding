#include<iostream>
using namespace std;


int main()
{
	int t,sum,ang;
	int n;
	cin>>t;
	while(t-- >0)
	{
		
		n=3;
	
		sum=0;
		while(n-- >0)
		{
			cin>>ang;
			//if(ang>1)
				sum += ang;
			//else
			 //sum -= sum;
		}
		if(sum == 180)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
	
}
