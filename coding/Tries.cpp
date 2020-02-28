#include<iostream>
#include<unordered_map>
#include <cstring>
#include<utility>
using namespace std;

class Node{
	public:
		char key;
		
		bool isterminal;
		unordered_map<char,Node*> h;
		Node()
		{
			//key = 'g';	
		}
		Node(char k)
		{
			key = k;
			isterminal=false;
		}
		
};

class Tries
{
	Node *root;
	
	public:
		Tries()
		{
			root=new Node('\0');
		}
		
		
		void insert(string word)
		{
			
			Node *temp = root;
			
			char k;
			for(int i=0;word[i]!='\0';i++)
			{	
				k=word[i];
				
				if(temp->h.count(k)==0)
				{
					//cout<<"i m here"<<endl;
					Node *newnode = new Node(k);
					temp->h[k] = newnode;
					temp = newnode;
				}
				else
				{
					temp = temp->h[k];
				}
				
			}
			temp->isterminal =true;
		}
		
		bool find(string word)
		{
			Node *temp = root;
			for(int i=0;i<word.length();i++)
			{
				if(temp->h.count(word[i])==0)
				{
					return false;
				}
				else
				{
					temp=temp->h[word[i]];
				}
				
			}
			
			return temp->isterminal;
		}
};

int main()
{
	Tries t;
	t.insert("apple");
	
	t.insert("ape");
	t.insert("bad");
	t.insert("you");
	t.insert("come");
	t.insert("wait");
	
	bool f = t.find("apple");
	
	if(f)
	{
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}

	return 0;	
}
