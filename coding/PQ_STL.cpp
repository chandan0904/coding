#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,string> pis;
class IntCompare{
public:
    bool operator()(int a, int b){
        if (a>b) return true; else return false;
        ///return a>b;
    }
    bool operator()(pis a, pis b){
        if (a.first>=b.first) return true; else return false;
    }
};


int main(){
    ///priority_queue<int> pq;
    priority_queue<int,vector<int>,IntCompare> pq;
    pq.push(3);
    pq.push(6);
    pq.push(4);
    pq.push(7);
    pq.push(1);
    pq.push(8);
    pq.push(5);
    pq.push(2);
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    priority_queue<pis, vector<pis>, IntCompare> pq1;
    pq1.push(make_pair(2,"Item:1,P2"));
    pq1.push(make_pair(2,"Item:2,P2"));
    pq1.push(make_pair(1,"Item:1,P1"));
    pq1.push(make_pair(2,"Item:3,P2"));
    pq1.push(make_pair(1,"Item:2,P1"));
    while (!pq1.empty()){
        cout<<pq1.top().second<<endl;
        pq1.pop();
    }

}
