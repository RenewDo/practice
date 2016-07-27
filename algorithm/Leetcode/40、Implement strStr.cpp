class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = haystack.size(), b= needle.size();
        if(a<b)
           return -1;
        else if(b==0) return 0;
        int k;
        for(int i=0; i<a-b+1; i++)
           for(int j=0,k=i; j<b&&k<a; j++, k++)
           {
                if(haystack[k]!=needle[j])
                   break;
                if(j==b-1 && haystack[k]==needle[j])
                   return k-j;
           }
       return -1;
    }
};
