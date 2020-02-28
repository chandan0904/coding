#include<iostream>
#include<vector>
#include<ctime>
#include<array>
#include<cstring>
#include<bitset>
using namespace std;


////////////isSorte//////////
bool isSorte(int *arr,int n)
{
	//cout<<"i am here"<<endl;
	if(n==1)
		return true;
		
	if(arr[0]<arr[1] && isSorte(arr+1,n-1) )
	{
		//cout<<arr[0]<<" "<<arr[1]<<endl;
		return true;
	}
	
	return false;
}

//////////////FAST POWER/////////

int fastPower(int a,int n)
{
	if(n==0)
		return 1;
	if(n&1)
	{
		int ans = fastPower(a,(n-1)/2);
		return a*ans*ans;
	}
	else
	{
		int ans = fastPower(a,(n)/2);
		return ans*ans;
	}	
}
///////////STRING TO NUMBER////////////////////
int stringToNo(char *str,int n)
{
	if(n==0) return 0;
	if(n==1)
	{
		return ((int)str[0] )- 48;
	}
	return 10*stringToNo(str,n-1)+(str[n-1]-48);
}


////////////////MULTIPLICATION////////////////
int multiplication(int a,int b)
{
	if(b==0)
		return 0;
	if(b>0)
		return a + multiplication(a,b-1);
	if(b<0)
		return multiplication(a,b+1) -a;
}

////////////2048PROBLEM////////////

string intToNo(int num,string str[])
{
	if(num==0)
		return "";
		
	return intToNo(num/10,str)+str[num%10];
}
/////////////BOBBLE SORT//////////
void bobbleSort(int arr[],int i,int n)
{
	if(n==1)
		return;
	
	if(i==n-1)
		return bobbleSort(arr,0,n-1);
	
	if(arr[i]>arr[i+1])
	{
		swap(arr[i],arr[i+1]);
		
	}
	bobbleSort(arr,i+1,n);
}

///////////////tiling problem/////////////

int tiling(int a,int n)
{
	
	if(n<=1|| n<a)
	{
		return 1;
	}
	if(n==a)
	{
		return 2;
	}
	//if(n<a) return 0;
	return tiling(a,n-1)+tiling(a,n-a);
}

////////////////////tower of hanoi///////

void toh(int n,char src, char des,char helpr)
{
	if(n==0)
		return ;
	
	toh(n-1,src,helpr,des);
	cout<<"move "<<n<<" disk from "<<src<<" to "<<des<<endl;
	toh(n-1,helpr,des,src);
}
//////////////QUICK SORT//////////////


int pivot(int *arr,int c,int end)
{
	int i=c-1;
	
	for(;c<end;c++)
	{
		if(arr[c]<arr[end])
		{
			i++;
			swap(arr[i],arr[c]);
		}
	}
	i++;
	swap(arr[i],arr[end]);
	return i;
}

void quickSort(int *arr,int l,int r)
{
	if(l>=r)
		return ;
		
	int p = pivot(arr,l,r);
	quickSort(arr,l,p-1);
	quickSort(arr,p+1,r);
	
}
/////////////////////RANDOMIZE QUICK SORT///////////////
void randQuickSort(int *arr,int n)
{
	int j;
	//n= sizeof(arr);
	srand(time(NULL));
	for(int i=n-1; i>0;i--)
	{
		j=rand()%(i+1);
		//cout<<j<<endl;
		swap(arr[i] , arr[j]);
	}
	
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	quickSort(arr,0,n-1);
	
}

/////////////////////////SUB SEQUENCE/////////////

void subSequence(char *str,char *seq,int spos,int pos)
{
	if(str[pos]=='\0')
	{
		seq[spos]='\0';
			for(int i=0;seq[i]!='\0';i++)
			{
				cout<<seq[i];
			}
			cout<<endl;
			return ;
	}
	seq[spos]=str[pos];
	subSequence(str,seq,spos+1,pos+1);
	

	subSequence(str,seq,spos,pos+1);
	
}
////////////////PHONE KEYPAD/////////////////
void phoneKeypad(char *keypad[],char input[],char output[],int pos,int opos)
{
	
	if(input[pos]=='\0' )
	{
		output[pos]='\0';
		for(int i=0;output[i]!='\0';i++)
		{
			cout<<output[i];
		}
		cout<<endl;
		return ;
	}
	//cout<<"huihefui"<<endl;
	int i=0;
	if(input[pos]-'0' == 1 || input[pos]-'0' == 0 )
	{
		phoneKeypad(keypad,input,output,pos+1,opos);
	}
	while(keypad[input[pos]-'0'][i]!='\0')
	{
		output[opos]=keypad[input[pos]-'0'][i];
		phoneKeypad(keypad,input,output,pos+1,opos+1);
		i++;
	}
}


/////////////PERMUTATION ////////////
void permutation(char str[],int e)
{
	if(str[e]=='\0')
	{
	//	out[e]='\0';
		cout<<str<<endl;
		return ;
		
	}
	

	for(int i=e;str[i]!='\0';i++)
	{
		swap(str[i],str[e]);
		permutation(str,e+1);
		swap(str[i],str[e]);
	}
	
}
/////////N-Q PROBLEM/////////
#define M 10
#define N 5
bool isSafe(bool arr[N][N],int i,int j,int n)
{
	for(int k =0; k<i ;k++)
	{
		if(arr[k][j]==1)
		return false;
	}
	
	for(int k=i-1,l=j-1; k>=0 && l>=0; k--,l--)
	{
		if(arr[k][l]==1)
		{
			return false;
		}
	}
	for(int k=i-1,l=j+1;k>=0 && l<n;k--,l++)
	{
		if(arr[k][l]==1)
		{
			return false;
		}
	}
	return true;
}
void nQ_Problem(bool arr[][N],int i,int n)
{
	if(i>=n)
	{
		for(int k=0;k<n;k++)
		{
			for(int l=0;l<n;l++)
			{
				cout<<arr[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return ;
	}
	
	for(int j=0;j<n;j++)
	{
		if(isSafe(arr,i,j,n))
		{
			arr[i][j]=1;
			nQ_Problem(arr,i+1,n);
			//return true;
			arr[i][j]=0;
		}
		
		
	}

	
}

/////////////////////////////RAT IN A MAZE//////////
void ratInMaze(bool maze[5][5],bool path[5][5],int i,int j,int m,int n)
{
	if(i==m-1 && j==n-1)
	{
		for(int k=0;k<m;k++)
		{
			for(int l=0;l<n;l++)
			{
				cout<<path[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return ;
	}
	if(maze[i][j+1]!=0&& j<n)
	{
		path[i][j]=1;
		ratInMaze(maze,path,i,j+1,m,n);
		path[i][j]=0;
	}
	if(maze[i+1][j]!=0&& i<m)
	{
		path[i][j]=1;
		ratInMaze(maze,path,i+1,j,m,n);
		path[i][j]=0;
	}
	
	
	
}
////////////N-Q PROBLEM USIG BITSET///////////////
void nQ_Bitset(bitset<N> bord[N],bitset<N> &col,bitset<2*N> &d1,bitset<2*N> &d2,int i,int n)
{
	if(i>=n)
	{
		
	//1101 1011 0101 1111 ;
	//bitset<N*N> bord(string("1101101101011111"));
	//cout<<bord<<endl;;
		for(int k=0;k<N;k++)
		{
			for(int l=0;l<N;l++)
			{
				//(
				//cout<<(l+(k*N))<<" ";
				cout<<bord[k][(N-1)-l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return ;
	}
	//cout<<"im here"<<endl;
	for(int j=0;j<n;j++)
	{
		if(!col[j] && !d1[i-j+(n-1)] && !d2[i+j])
		{
			col[j] = d1[i-j+(n-1)] = d2[i+j] = 1;
			bord[i][(N-1)-(j)]=1;
			nQ_Bitset(bord,col,d1,d2,i+1,n);
			//return true;
			bord[i][(N-1)-(j)]=0;
			col[j] = d1[i-j+(n-1)] = d2[i+j] = 0;
			//arr[i][j]=0;
		}
		
		
	}

	
}
int main()
{
	bitset<N> bord[N];
	bitset<2*N> d1,d2;
	bitset<N> col;
	
	nQ_Bitset(bord,col,d1,d2,0,N);
	/*bool maze[5][5]={
	{1, 0, 0, 0, 0},
   	{1, 1, 1, 1, 1},
   	{1, 0, 1, 1, 1},
   	{1, 0, 0, 1, 0},
   	{1, 1, 1, 1, 1}
					};
	
	bool path[5][5]={0};			
	ratInMaze(maze,path,0,0,5,5);
	
	
	bool arr[N][N]={0};
	
	nQ_Problem(arr,0,4);
	/*
	char str[]="abc";
	permutation(str,0);
	
	/*char *phonekeypad[] = {
		"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"	};
	char input[] = "511035";
	char output[10]="";
	phoneKeypad(phonekeypad,input,output,0,0);
	/*char *str;
	str = "abc";
	char seq[4]="";
	subSequence(str,seq,0,0);
	
	/*int arr[]={1,22,4,77,5,6,7,8};
	randQuickSort(arr,8);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	//toh(4,'A','C','B');
	//cout<<tiling(4,7)<<endl;
	/*int arr[]={1,7,12,6,4,8,9};
	bobbleSort(arr,0,7);

	*/
	/*string digit[10];
	digit[0]="Zero ";
	digit[1]="One ";
	digit[2]="Two ";
	digit[3]="Three ";
	digit[4]="Four ";
	digit[5]="Five ";
	digit[6]="Six ";
	digit[7]="Seven ";
	digit[8]="Eight ";
	digit[9]="Nine ";
	cout<<intToNo(1234,digit);*/
	//cout<<multiplication(15,20);
	//int arr[] = {1,3,5,6,7,12,14};
	//char str[] = "2435";
	//cout<<stringToNo(str,4);
	//cout<<'1'-48;
	
	//cout<<fastPower(2,5);
	/*if(isSorte(arr,7))
	{
		cout<<"Sorted "<<endl;
		
	}
	else
	{
		cout<<"nod Sorted "<<endl;
		
	}*/
	return 0;
}
