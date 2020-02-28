#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> V;
    V.push_back(11);
    V.push_back(12);
    V.push_back(13);
    V.push_back(14);
    V.push_back(15);
    V.push_back(16);
    cout<<V.size()<<endl;
    cout<<V.empty()<<endl;
    cout<<V[2]<<endl;
    V[2]=22;
    cout<<V[2]<<endl;
    cout<<V.front()<<endl;
    cout<<V.back()<<endl;
}


