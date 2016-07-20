class Solution {
public:
    string getPermutation(int n, int k) {
       string s(n, '1');
       for(int i=0; i<n; i++)
         s[i]= i+s[i];
      return findk(s,k);
    }

private:
   int f(int n)
   {
       int res = 1;
       for(int i=1; i<=n;i++)
       res*=i;
       return res;
   }
   string findk(const string &s, int k)
   {
       string seq(s);
       string res;
       int len = s.size();
       int base = f(len-1);
       k--;
       for(int i=len-1; i>0;k%=base, base/=i ,i--)
       {
           auto a = next(seq.begin(),k/base);
           res.push_back(*a);
           seq.erase(a);
       }
       res.push_back(seq[0]);
       return res;
   }
};
