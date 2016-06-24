// string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

class reverseCake
{
public:
	reverseCake(vector<int> &init, int n) :cakes(init), num(n), curSwap(init), search_(0)
	{   
	          maxSwap = (num-1)*2;
	}

	void run(int i)
	{
    	search_++;
		if(isSort())
		{ 
	 	  if(i < maxSwap)
			{
			cout<< "search step "<<search_<<endl;
			cout<< "max step "<<maxSwap<<endl;
			for(int m=0; m<num; m++)
				{
				   cout << curSwap[m];
				}
			}
		  return ;
		}

		if(i + low() > maxSwap)
             return;
 
		f.clear();
	   for(int j=1 ; j<num; j++)
	   {
	        swap(0, j);
			search(i+1);
			swap(0,j);
		}
	    for(int j=1 ; j<num; j++)
	   {
	        swap(0, j);
			run(i+1);
			swap(0,j);
		}
	}

private:

	int low()
	{
	     int low=0;
	       for(int i=1; i<num; i++)
		  {
		  if(curSwap[i-1]-curSwap[i]!=1 && curSwap[i-1]-curSwap[i]!=-1 )
			  {
			      low ++;
			  }
		  }
		   return low;
	}

	bool isSort()
	{
	     for(int k=1; k<num; k++)
	     {
		       if(curSwap[k] < curSwap[k-1])
				  return false;
		 }
		 return true;
	}

	void swap(int a, int b)
	{
	   for(;a<b; a++,b--)
	   {
	        int t = curSwap[a];
	        curSwap[a] = curSwap[b];
	         curSwap[b] = t;
		}
 	}

	void search(int i)
	{
	      int fn = 0; 
	      for(int k=num-1; k>=1; k--)
			  {
			      if(k==curSwap[k])
					  continue;
				  else if(curSwap[k-1] > curSwap[k])
					           fn++;
			  }
		  f.insert(pair<int, int>(fn, i));
	}
private:
	vector<int> cakes;
	int  num;
	int maxSwap;
	vector<int> curSwap;
	int search_;
	multimap<int, int> f;
};

int main()
 {
 int ar[]={4,2,1,3};
 vector<int> b(ar, ar+4);
  reverseCake a(b,4);
    a.run(0);
	return 0;
}

