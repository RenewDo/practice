// string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <algorithm>
using namespace std;

class reverseCake
{
public:
	reverseCake(vector<int> &init, int n) :cakes(init), num(n), curSwap(init),search(0)
	{   
	          maxSwap = (num-1)*2;
	}

	void run(int i)
	{
    	search++;
		if(isSort())
		{ 
	 	  if(i < maxSwap)
			{
			cout<< "search step "<<search<<endl;
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

private:
	vector<int> cakes;
	int  num;
	int maxSwap;
	vector<int> curSwap;
	long long search;
};

int main()
 {
 int ar[]={3,2,1,6,5,4,9,8,7,0};
 vector<int> b(ar, ar+10);
  reverseCake a(b,10);
    a.run(0);
	return 0;
}
