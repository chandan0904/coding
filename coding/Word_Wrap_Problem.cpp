#include<bits/stdc++.h>
#include<iostream>
#define inf 100000
using namespace std;

int arr[1000];

void prints(int p[],int n)
{

	 
	if(p[n] == 0)
		return ; 
		
	prints(p, p[n]-1); 
	cout<<p[n]<<" "<<n<<" "; 

	
}


void word_wrap(int n,int m)
{
    int espace[n+1][n+1]={0};
    int costl[n+1][n+1] ={0};
    	
    /*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",espace[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",costl[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");*/
    
    int len=0,k;
    for(int i=1;i<=n;i++)
    {
       
        espace[i][i] = m-arr[i-1];
        //len = arr[i];
        
        for(int j=i+1;j<=n;j++)
        {
            espace[i][j] = espace[i][j-1]- arr[j-1] -1;
            
        }
    }
    
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		if(espace[i][j]<0)
    		{
    			costl[i][j]=inf;
			}
			else if(j==n && espace[i][j]>=0)
				costl[i][j]=0;
				
			else
				costl[i][j] = espace[i][j]*espace[i][j];
		}
	}
    
    int c[n+1],p[n+1];
    c[0]=0;
    p[0]=0;
    for(int j=1;j<=n;j++)
    {
    	c[j]=inf;
    	for(int i=1;i<=j;i++)
    	{
    		if(c[i-1]!=inf && costl[i][j]!=inf && c[i-1]+costl[i][j]<c[j])
    		{
    			c[j] =c[i-1]+costl[i][j];
    			p[j]=i;
			}
		}
	}


	/*for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",espace[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",costl[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

	for(int i=0;i<=n;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
	
	for(int i=0;i<=n;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;*/
	prints(p,n);
	
    
}

int main()
{
    int t;
    cin>>t;
    /*memset(arr,0,sizeof(arr));
    for(int i=0;i<100;i++)
    {
    	for(int j=0;j<100;j++)
    	{
    		printf("%d",arr[i][j]);
		}
	}*/
    while(t-->0)
    {
       
       int n,m;
       cin>>n; 
       for(int i=0;i<n;i++)
       {
           scanf("%d",&arr[i]);
       }
       scanf("%d",&m);

       vector<int> ans;
       word_wrap(n,m);


       printf("\n");  
    }


    return 0;
}
