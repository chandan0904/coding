#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
private:
    int data;
    Node** children;
    int child_count;
public:

    Node(int d){
        data=d;
        children=NULL;
        child_count=0;
    }
    int GetData(){
        return data;
    }
    friend class GenericTree;
};

class MyClass{
public:
    Node* nd;
    int MaxSum;
};

class GenericTree{
private:
    Node* root;
    
    void verticalOP(Node *rt,map<int,vector<int> > &m,int d=0)
	{
		//cout<<rt->data<<" ";
		//cout<<" i m h"<<endl;
		m[d].push_back(rt->data);
        for(int i=0;i<rt->child_count; i++)
        {
            
            verticalOP(rt->children[i],m,d+1);
        }
		
	}
public:
    GenericTree(){
        root=NULL;
    }

    void InsertLO(){
        int d,c;
        cout<<"enter data for root:";
        cin>>d;
        root=new Node(d);
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* f=q.front();
            q.pop();
            cout<<"Enter No of Children for Node "<<f->data<<":";
            cin>>c;
            f->child_count=c;
            f->children=new Node* [c];
            for (int i=0;i<c;i++){
                cout<<"enter child#"<<i<<" of Node "<<f->data<<":";
                cin>>d;
                f->children[i]=new Node(d);
                q.push(f->children[i]);
            }
        }
    }
	
	
	
	void vertiaclOP()
	{
		map<int,vector<int>> m;
		//cout<<" jff"<<endl;
		verticalOP(root,m);
		//cout<<" jff"<<endl;
		map<int,vector<int>>::iterator itr;
		itr = m.begin();
		while(itr!= m.end())
		{
			//cout<<"in loop "<<endl;
			//cout<<"size "<<itr->second.size()<<endl;
			for(int i=0; i<itr->second.size();i++)
			{
				//cout<<"in inerloop "<<endl;
				cout<<itr->second[i]<<" ";
			}
			cout<<endl;
			itr++;
		}
	}


};

int main(){
    GenericTree gt;
    ///gt.InsertPO();
    gt.InsertLO();
    gt.vertiaclOP();
    return 0;
}

/*
1 2 2 3 2 4 5 2 6 7 0 1 8 1 9 0 0 0
*/

