#include<bits/stdc++.h>

using namespace std;
template<typename T,typename U>
class point{
	private:
		T x;
		U y;
	public:
		get(T a,U b)
		{
			x=a;
			y=b;
		}
		display()
		{
			cout<<"x = "<<x<<" y = "<<y<<endl;
			cout<<endl;
		}
	
};

template<typename tmplt>
class test{
	private:
		tmplt x,y,z;
	public:
		get(tmplt a,tmplt b,tmplt c)
		{
			x=a;
			y=b;
			z=c;
		}
		display()
		{
			cout<<"x = "<<x<<endl;
			cout<<"y = "<<y<<endl;
			cout<<"z = "<<z<<endl;
		}
		
};

template<typename type>
class mystack{
	private :
		vector<type> v;
	
	public:
		
		void push(type d)
		{
			v.push_back(d);
		}
		
		void pop()
		{
			v.pop_back();
		}
		
		type top()
		{
			return v[v.size()-1];
			
		}
		int size()
		{
			return v.size();
		}
		bool isEmpty()
		{
			if(v.size()==0) return true;
			
			return false;
		}
};

int main()
{

	mystack<point<int,char>> s;

	for(int i=0;i<10;i++)
	{
		point<int,char> p;
		p.get(1*i,65+i);
		s.push(p);
	}
	point<int,char> p;
	while(!s.isEmpty())
	{
		p=s.top();
		cout<<"size of stack : "<<s.size()<<endl;
		p.display();
		s.pop();
	}




	/*
	test<int> t1;
	test<string> t2;
	test<float> t3;
	t1.get(1,3,5);
	t2.get("Adsf","fhfifdfh","euir");
	t3.get(23.2,3.3,4.4);
	t1.display();
	t2.display();
	t3.display();
	/*point<int> p;
	p.get(3,5);
	p.display();
	*/
	return 0;
}
