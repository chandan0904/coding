#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > ppii;

struct CustomCompare
{
    bool operator()(pair<int,int> p1, pair<int,int> p2)
    {
        return p1.first <p2.first;
    }

    /*bool operator()(const Person& lhs, const Person& rhs)
    {
        return lhs.getAge() < rhs.getAge();
    }*/
};

int main()
{
	
	set<pii,CustomCompare> openList;
	openList.insert(make_pair(15,1) );
	openList.insert(make_pair(150,13) );
	openList.insert(make_pair(5,14) );
	openList.insert(make_pair(10,13) );
	openList.insert(make_pair(1,15) );
	openList.insert(make_pair(115,10) );
	/*openList.insert(make_pair(10,make_pair(0,4)));
	openList.insert(make_pair(5,make_pair(0,4)));
	openList.insert(make_pair(115,make_pair(0,4)));
	openList.insert(make_pair(151,make_pair(0,4)));*/
	while(!openList.empty())
	{
		pii node=*openList.begin();
		openList.erase(openList.begin());
		cout<<node.first<<" "<<node.second<<endl;
	}
	return 0;
}
