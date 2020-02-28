#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int t,n,a,index;
	vector<int> arr;
	cin>>t;

	
	while(t-- >0)
	{
		cin>>n;
		arr.resize(n);
		index=0;
		for(int i=0; i<n; i++)
		{
			cin>>a;
			arr[i] = a;
		}
		
		for(int i=1; i<n; i++)
		{
			if(arr[index] > arr[i] )
			{
				index =i;
			}
		}
		cout<<index+1<<endl;
		arr.clear();
	}
	
	return 0;
	
}
