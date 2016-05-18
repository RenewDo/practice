#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n ;
    while(cin>>n)
    {
	    vector<int> res;        
        int i=0;
        while(i<n)
        {
		    vector<int> times(26, 0);
	    	string s;
            cin>>s;
            for(int j=0; j<s.size();++j)
            {
                if(s[j]<'a')
                    times[s[j]-'A']++;
                else
                    times[s[j]-'a']++;
            }
            sort(times.begin(),  times.end());
            int sum = 0;
            for(int j=0; j<26;++j)
                 sum += (j+1)*times[j];
			res.push_back(sum);
            i++;
        }
		for(vector<int>:: iterator it=res.begin(); it!=res.end(); ++it)
			cout<<*it<<endl;
    }  
    return 0;
}
