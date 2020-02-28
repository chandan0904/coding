#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{
bitset<10> subkeys[16];
cout<<"sizeof(subkeys) "<<sizeof(subkeys)<<endl;
for(int i=0;i<16;i++)
{
	for(int j=0;j<16;j++)
	{
		cout << subkeys[i][i]<<" "; 	
	}
	cout << endl;
}


return 0;
}

