#include<bits/stdc++.h>
using namespace std;

int histogramArea(int bar[],int n)
{
	stack<int> st;
	int i=0;
	int current;
	int area,maxArea=0;
	st.push(i++);
	while(!st.empty())
	{
		while(!st.empty() && bar[st.top()]> bar[i]  || !st.empty()&& i>=n)
		{
			current = bar[st.top()];
			st.pop();
			if(st.empty())
			{
				maxArea = max(maxArea,(current * i ));	
				//cout<<"Stack empty , i = "<<i<<"  current = "<<current<<" ,  area = "<<maxArea<<endl;			
			} 
			else{
				maxArea = max(maxArea,(current *(i-st.top() -1) ));	
				//cout<<"Stack not empty , i = "<<i<<"  current = "<<current<<"  st.top() = "<<st.top()<<" , area = "<<maxArea<<endl;
			}
			
		}
		
		if(i<n)
			st.push(i);
		
		i++;
	}
	return maxArea;	
}



int main()
{
	int bar[7]={6,4,5,4,5,4,6};
	
	cout<<" Histogram Area "<<histogramArea(bar,7);
	
	return 0;
}
