#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool contain(int n)
{
	char str[5];
	sprintf(str,"%d", n);
	if(strchr(str, '7') == NULL)
		return false;
	else return true;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int count = 0;
		for(int i=1; i<=n; ++i)
		{
			if(i%7==0 || contain(i))
				count++;
		}
		cout<<count;
	}
	return 0;
}
