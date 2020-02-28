#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    
    int row1,row2,cal1,cal2;
    row1 = cal1=0;
    row2 = A.size();
    cal2= A[0].size();
    vector<int> v;
    cout<<"r1 = "<<row1<<" r2 "<<row2<<" c1 = "<<cal1<<" c2 = "<<cal2<<endl;
   
    /*if((row1==row2 )&& (cal1==cal2))
    {
    	cout<<"i m here"<<endl;
    	v.push_back(A[row1][cal1]);
    	return v;
	}*/
    while(row1<row2 && cal1<cal2)
    {
    
        for(int i=cal1;i<cal2;i++)
        {
        	cout<<A[row1][i]<<" ";
            v.push_back(A[row1][i]);
        }
        row1 +=1;
        
        for(int i=row1;i<row2;i++)
        {
        	cout<<A[i][cal2-1]<<" ";
            v.push_back(A[i][cal2-1]);
        }
        
        cal2 -= 1;
        
        for(int i=cal2-1;i>=cal1 && row1<row2;i--)
        {
        	cout<<A[row2-1][i]<<" ";
            v.push_back(A[row2-1][i]);
        }
        row2 -=1;
        for(int i=row2-1;i>=row1 && cal1<cal2;i--)
        {
        	cout<<A[i][cal1]<<" ";
            v.push_back(A[i][cal1]);
        }
        cal1 +=1;
    }
    
    return v;
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int>> A(m,vector<int>(n));
	cout<<m<<" n "<<n<<endl;
	cout<<"enter : "<<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>A[i][j];
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"hii"<<endl;
	vector<int> v;
	v =spiralOrder(A);
	cout<<"output "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}
