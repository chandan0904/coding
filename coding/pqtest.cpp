#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Compare{
public:
	bool operator()(int p1,int p2)
	{
		return p1>p2;
	}
};

int main()
{
	int a;
	priority_queue<int, std::vector<int>, Compare > q;
	for(int i=0;i<5;i++)
	{
		cout<<"enter a : ";
		cin>>a;
		q.push(a);
	}
	
	while(!q.empty())
	{
		a=q.top();
		q.pop();
		cout<<a<<" ";	
	}
	return 0;
}
