#include<iostream>
#include<Queue>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

void runningMedian(vector<int> &arr)
{
	priority_queue<int,vector<int>,greater<int> > minPq;
	priority_queue<int> maxPq;
	int s,i=0;
	int ln,rn;
	ln=rn=0;
	s=arr.size();
	int median;
	maxPq.push(arr[i++]);
	ln++;
	while(i<s)
	{
		if(ln==rn)
		{
			median = (minPq.top() + maxPq.top())/2;
		}
		else if(ln<rn)
		{
			median =(minPq.top());
		}
		else //if(ln>rn)
		{
			median =(maxPq.top());
		}
		
		////////push in the Queue///////////////////////////
		
		if(arr[i]!=-1) 
		{
			if(ln>=rn  && median<arr[i])
			{
				minPq.push(arr[i]);
				rn++;
			}
			else if(ln<=rn  && median>arr[i])
			{
				maxPq.push(arr[i]);
				ln++;
			}
			else if(ln<rn && median<arr[i])
			{
				maxPq.push(minPq.top());
				minPq.pop();
				ln++;
				minPq.push(arr[i]);
				//rn++;
			}
			else if(ln>rn && median>arr[i])
			{
				//cout<<" ln > rn "<<endl;				
				minPq.push(maxPq.top());
				maxPq.pop();
				rn++;
				maxPq.push(arr[i]);
				
			}
			
		}
		else
		{
			cout<<"MEDIAN = "<<median<<endl;
		}
		
		i++;
	}
	//cout<<i<<endl;
	
}
int main()
{	
	vector<int> arr={1,2,3,9,8,4,3,2,9,1,-1,5,9,10,5,2,4,3,-1,4,8,9,6,23,56,-1,35,34,56,34,12,34,423,42,423,423,45,-1};
	////////////////1 1 2 2 2 3 3 3 4 4 4 5 5 6 8 8 9 9 9 9 10 12 23 34 34 34 35 42 44 56 56 423 423 423 
	/*FILE *fptr;
	fptr = fopen("Output_File.txt","w a");
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++)
	{
		fprintf(fptr,"%d ",arr[i]);
	}
	fclose(fptr);
	*/
	runningMedian(arr);
	
	return 0;
}



