#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	vector<int> liss(n, 0);
	vector<int> ldss(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		for(int j=0; j<i; ++j)
		{
			if(arr[i]>arr[j] && liss[i]<(liss[j]+1))
			liss[i] = liss[j]+1;
		}
	}

	for(int i=n-1; i>=0; --i)
	    for(int j=n-1; j>i; --j)
			if(arr[i]>arr[j] && ldss[i]<ldss[j]+1)
				 ldss[i] = ldss[j]+1;
	int max=0;
	for(int i=0; i<n; i++)
	{
		if(max<liss[i]+ldss[i])
			max = liss[i]+ldss[i]; 
	}
	cout<<n-max-1<<endl;
	return 0;
}
