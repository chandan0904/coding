#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

typedef pair<int,int> pii;


struct MyCompar{
	
	bool operator()(pii d1,pii d2)
	{
		return d1.first>d2.first;
	}
};

vector<int> margeSortedArray(vector<vector<int>> &arr)
{

	vector<int> s;
	vector<int > itr;
	for(int i=0;i<arr.size();i++)
	{
		s.push_back(arr[i].size() );
		itr.push_back(0);
	}
	vector<int> newArr;
	
	priority_queue<pii,vector<pii>,MyCompar> pq;
	
	for(int i=0;i<arr.size();i++)
	{
		pq.push(make_pair(arr[i][0],i));	
		++itr[i];
	}
	
	pii temp;
	
	while(pq.top().first !=INT_MAX)
	{
		
		temp = pq.top();
		pq.pop();
		newArr.push_back(temp.first);
		int i = temp.second;
		if( itr[i]<s[i] )
		{
			
			pq.push(make_pair(arr[i][ itr[i] ],i) );
			++itr[i];
		}
		else if( itr[i]==s[i] )
		{
			
			pq.push(make_pair(INT_MAX,i) );
			++itr[i];;
		}
		
	}
	return newArr;
}

int main()
{
	vector<vector<int> > arr = { {1,5,9,14,20},{4,6,8,10,12,13,15},{2,9,11,16,17,18},{2,3,45,60}};
		
	vector<int> sortedArr;	
	sortedArr = margeSortedArray(arr);		
	for(int i=0;i<sortedArr.size();i++)
	{
		printf("%d ",sortedArr[i]);
	}
	
	return 0;
}
