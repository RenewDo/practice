#include "stdafx.h"
#include <iostream>
#include<vector>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T>
class Cqueue
{
public:
	Cqueue(int n): size(n),num(0)
		{
		        first_mem = new T[n];
				last_mem =  first_mem + n-1;
                first = first_mem;
				last = first_mem;
		}
	  void push(T value)
	     {
		          if(num == size)
					  {
					         cout<<"queue is full !"<<endl;
							 return ;
					  }
				  *first = value;
				  num++;
				  if(first == last_mem)
					     first = first_mem;
				  else first++;
		  }
	 T pop()
		  {
		        if(num == 0)
					{
					     cout << "queue is empty !"<<endl;
						 return 0;
					}
				T tmp = *last;
				if(last == last_mem)
					     last = first_mem;
				  else last ++;
				num--;
				return tmp;
		  }
	 ~Cqueue()
		 {
		    delete [] first_mem;
		 }
private:
	int num;
	int size;
	T* first_mem;
	T* last_mem;
	T* first;
	T* last;
};

int main()
 {
   Cqueue<int> que(10);
   for(int i=1; i<=11; i++)
	  que.push(i);
   for(int j=1; j<=5; j++)
	   que.pop();
   for(int k=100; k>=97; k--)
	   que.push(k);
   int tmp;
   for(int j=1; j<=11; j++)
	   {
	     tmp = que.pop();
		 cout<<tmp<<endl;
	   }
   
	return 0;
}
