#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

#define s(x) scanf("%lld",&x);
#define p(x) printf("%lld\n",x)
#define ll long long int
#define v vector<string>
#define vv vector<vector<string>>

struct Node{
	char key;
	unordered_map<char,Node*> h;
	bool isend;
	
	Node()
	{
		
	}
	Node(char k)
	{
		key =k;
		isend = true;
	}	
};



bool search(Node *rt,string word)
{
	Node *temp = rt;

	for(int i=0;word[i]!='\0';i++)
	{
		char k = word[i];
		if((temp->h).count(k)==0)
		{
			return false;
		}
		else
		{
			temp = temp->h[k];
		}
	}
	return true;
}

void insert_word(v &crossword,int i,int j,int m,Node *rt)
{
	if(i<m && i>=0 && j<m && j>=0 && crossword[i][j]!='*' )
	{
		char k = crossword[i][j];
		crossword[i][j] = '*';
		
		if(rt->h.count(k)==0)
		{
			rt->h[k] = new Node(k);
			rt = rt->h[k];
		}
		else
		{
			rt = rt->h[k];
		}
		
		insert_word(crossword,i+1,j,m,rt);
		insert_word(crossword,i-1,j,m,rt);
		insert_word(crossword,i,j+1,m,rt);
		insert_word(crossword,i,j-1,m,rt);
		insert_word(crossword,i+1,j+1,m,rt);
		insert_word(crossword,i+1,j-1,m,rt);
		insert_word(crossword,i-1,j+1,m,rt);
		insert_word(crossword,i-1,j-1,m,rt);
		crossword[i][j]=k;
	}
}

int main()
{
	int n,m;
	Node *root = new Node('\0');
	
	s(n);
	
	v dictionary(n);
	for(int i=0;i<n;i++)
	{	
		cin>>dictionary[i];
	}
	
	s(m);
	
	v crossword(m);
	for(int j=0;j<m;j++)
	{
		cin>>crossword[j];
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			insert_word(crossword,i,j,m,root);
		}
	}
	set<string> st;
	for(string word:dictionary)
	{
		if(search(root,word))
		{
			st.insert(word);
		}
	}
	
	for(string str:st)
	{
		cout<<str<<" ";
	}
	return 0;
}

