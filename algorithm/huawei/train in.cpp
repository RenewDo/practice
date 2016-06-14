
#include <iostream>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <algorithm>
using namespace std;

bool isOut(vector<int>& in, vector<int>& out, int n)
{
		int in_index = 0, out_index = 0;
		stack<int> tmp;
		while(out_index < n)
		{
		        while(in_index < n)
				{
				        if(tmp.empty())
					    {
						       tmp.push(in[in_index]);
							   in_index++;
						}
						else if(out[out_index] != tmp.top())
						{
						       tmp.push(in[in_index]);
							   in_index++; 
						}
						else    break;
				}
				if(out[out_index] == tmp.top())
				{
				        tmp.pop();
						out_index++;
				}
				else break;
		}
		if(tmp.empty())
		       return true;
		else return false;
}

void perm(vector<int>& in, vector<int>& out, int i, int n)
{
       if(i==n)
		{
		      if(isOut(in, out, n))
			   {
			          for(int k=0; k<n; k++)
					 {
					        if(k == n-1)
								cout<<out[k]<<endl;
							else cout<<out[k]<<' ';
					}
			   }
			 
		}
	   else
	   {
            for(int j=i; j<n; ++j)
	     	{
		         swap(out[i], out[j]);
				 perm(in, out, i+1, n);
                 swap(out[j], out[i]);
		    }
	  }
}

int main()
 {
     int n;
	 while(cin>>n)
	{
	  vector<int> num(n, 0);
      vector<int> out(n, 0);
	  for(int i=0; i<n; i++)
	  {
	         cin>>num[i];
			 out[i] = num[i];
	  }  
	  perm(num,out, 0, n);
    }

	return 0;
}

