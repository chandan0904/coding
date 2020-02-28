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
	int i,j,k;
	i=j=k=1;
	cout<<arr.size()<<endl;
	int sa1,sa2,sa3;
	sa1= arr[0].size();
	sa2= arr[1].size();
	sa3= arr[2].size();
	int nws = sa1+sa2+sa3;
	vector<int> newArr;
	
	priority_queue<pii,vector<pii>,MyCompar> pq;
	pq.push(make_pair(arr[0][0],1));
	pq.push(make_pair(arr[1][0],2));
	pq.push(make_pair(arr[2][0],3));
	int c=0;
	pii temp;
	while(i<=sa1 || j<=sa2 || k<=sa3 )
	{
		
		temp = pq.top();
		//cout<<"size of pq "<<pq.size()<<endl;
		pq.pop();
		newArr.push_back(temp.first);
		//cout<<"size of pq "<<pq.size()<<endl;
		
		if(temp.second == 1 && i<sa1)
		{
			
			pq.push(make_pair(arr[0][i],1));
			i++;
		}
		else if(temp.second == 2 && j<sa2)
		{
		
			pq.push(make_pair(arr[1][j],2));
			j++;
		}
		else if(temp.second == 3 && k<sa3)
		{
			
			pq.push(make_pair(arr[2][k],3));
			k++;
		}
		
		///////////put MAx VALUE/////////////
		else if(i==sa1)
		{
			
			pq.push(make_pair(INT_MAX,1));
			//cout<<"i "<<i<<endl;
			i++;
		}
		else if(j==sa2)
		{
			
			pq.push(make_pair(INT_MAX,2));
			//cout<<"j "<<j <<endl;
			j++;
		}
		 else if(k== sa3)
		{
			
			pq.push(make_pair(INT_MAX,3));
			//cout<<" k "<<k<<endl;
			k++;
		}
		
		
		
		c++;
	}
	
	
	//cout<<endl;
	/*for(int i=0;i<nws;i++)
	{
		printf("%d ",newArr[i]);
	}*/
	return newArr;
}

int main()
{
	vector<vector<int> > arr = { {1,5,9,14,20},{4,6,8,10,12,13,15},{2,9,11,16,17,18} };
	
	/*arr[0] = {1,5,9,14,20};
	arr[1] = {4,6,8,10,12,13,15};
	arr[2] = {2,9,11,16,17};
	
	int arr1[]={1,5,9,14,20};
	int arr2[]={4,6,8,10,12,13,15};
	int arr3[]={2,9,11,16,17};
	int *arr[3];	
	*/
	vector<int> sortedArr;	
	sortedArr = margeSortedArray(arr);	
	
	
	
	for(int i=0;i<sortedArr.size();i++)
	{
		printf("%d ",sortedArr[i]);
	}
	
	return 0;
}
