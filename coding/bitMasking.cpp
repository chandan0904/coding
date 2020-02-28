#include<iostream>
#include<vector>
using namespace std;
/*
int setBit(int n,int i)
{
	return n|(1<<i);
}

int notSet(int n,int i)
{
	return n&(~(1<<i));
}

*/
///////////////////////////findTwoUniqueNo//////////////////////
void findTwoUniqueNo()
{
	vector<int> v;
	int n,a;
	cin>>n;
	
	for(int i=0;i<n; i++)
	{
		cin>>a;
		v.push_back(a);
	}
	
	int mask,bit=1;
	mask =v[0];
	for(int i=1; i<n; i++)
	{
		mask =mask^v[i];
	}
	
	while(!(mask&bit))
	{
		bit=bit<<1;
		cout<<bit<<endl;
	}
	
	//cout<< "  "<<(mask&1);
	
	int temp=0;
	for(int i=0; i<n; i++)
	{
		if((v[i]&bit) == (mask&bit))
		{
			temp = temp^v[i];
			//cout<<"  temp "<<temp<<"  ";
		}
	}
	cout<<endl;
	
	cout<<"1st no. : "<<temp<<endl;
	cout<<"2nd no. : "<<(mask^temp)<<endl;
	
}


//////////////finde one Unique no from a array in which 3 times another nos.//////////////////////////

void uniqueNo()
{
	int n,a;
	vector<int> arr;
	vector<int> cnt(64,0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		arr.push_back(a);
	}

	for(int i=0;i<n;i++)
	{
		int j=0;
		int num=arr[i];
		while(num>0)
		{
			cnt[j] += num&1;
			j++;
			num = num>>1;
		}
	}
	int ans=0;
	int p=1;
	for(int i=0;i<64;i++)
	{
		cnt[i] = cnt[i]%3;
		ans +=cnt[i]*p;
		p = p*2; 	
	}
	cout<<ans<<endl;
}

////////////INCREDIBLE HULK///////////

void incredibleHulk()
{
	int level;
	cin>>level;
	int num = level;
	int cnt=0;
	
	while(num>0)
	{
		cnt++;
		num = (num&(num-1));
	}
	cout<<cnt;
	
}

//////////LUCKY NO. ////////////////////
void luckyNo()
{
	long long ans=0;
	string str;
	cin>>str;
	
	int pos,len = str.length();
	
	ans = (1<<len) -2;
	
	for(int i=len-1,pos=0; i>=0 ; pos++,i--)
	{
		if(str[i]=='7')
		{
			ans += (1<<pos );
		}
	}
	
	cout<<ans+1;	
}


int main()
{
	int n;
	
	luckyNo();
	
	//incredibleHulk();
	//uniqueNo();
	//cout<<notSet(36,2);
	//cout<<setBit(16,3)<<endl;
	return 0;
}
