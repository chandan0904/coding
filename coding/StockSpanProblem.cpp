#include<bits/stdc++.h>

using namespace std;

void solve(int arr[],int n)
{
	stack<int> st;
	int day = 0;
	
	while(day<n)
	{
		
		
		while(!st.empty() && arr[st.top()]<=arr[day])
		{
			st.pop();
		}
		
		int beterDay = st.empty()?0:st.top();
		
		cout<<day-beterDay<<" ";
		day++;
		
	}
	
}

int main()
{
	int arr[10]={100,80,60,70,60,75,85,110,40,50};
	
	solve(arr,10);
	
	
	
	return 0;
}
