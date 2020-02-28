#include<bits/stdc++.h>
#include <iostream>

#include <cmath>
using namespace std;

 long double fun( long double x,long double y)
 {
 	long double v1;
 	long double v2;
 	long double sr;
 	long double srt;
 	long double ex;
 	
 	
     sr= (x*x +y*y);
 	
    srt = sqrt(sr);

 	
    ex = exp(-0.2);
    
	//cout<<" ex "<<ex<<endl;
	//cout << "sin(x) = " ;
    
    v1  = ex;
    
    v2 = 3*(sin(2*x) + cos(2*y));

    return v1+ v2;
    
 }

int main()
{
	
	int i,j; 
	int x,y;
	int max =INT_MAX;
	
	x=-35,y=35;
	i=-35;
	j=35;
	while(i<j)
	{
		int ans ;
		ans = fun(i,j);
		if(max>ans)
		{
			x=i;
			y=j;
			max  =ans;
		}
		i++;
	}
	
	i=-35;
	while(i<j)
	{
		int ans ;
		ans = fun(i,j);
		if(max>ans)
		{
			x=i;
			y=j;
			max  =ans;
		}
		j--;
	}
	
	//cout<<" x = "<<x<<" y = "<<y<<endl;
	cout<<"max ="<<max;
	
    return 0;
}
