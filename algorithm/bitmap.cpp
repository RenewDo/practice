#include <iostream>
#include <memory.h>
using namespace std;

char bitmap[4] ;

void add(int n)
{
      bitmap[n/8] |= (128 >> n%8);
}

bool search(int n)
{
        if(bitmap[n/8] & (128>>n%8))
			 return true;
		return false;
}

int main()
{
	int n[] = {2, 5, 7, 9, 25,};
	int i;

	memset (bitmap, 0, sizeof(bitmap));
	
	for( i=0; i<5; i++)
	      add(n[i]);

	for( i=0; i<5; i++)
	      if(search(n[i]))   
			  cout << "find " << n[i] <<endl;
		
    return 0;


}