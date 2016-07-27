class Solution {
public:
    string addBinary(string a, string b) {
           string res;
           reverse(a.begin(), a.end());
           reverse(b.begin(), b.end());
           const size_t n = a.size()>b.size()? a.size():b.size();
           int carry =0;
           for(int i=0;i<n; i++)
           {
               int val =0;
               int av = i<a.size()?a[i]-'0':0;
               int bv = i<b.size()? b[i]-'0':0;
               val = (av+bv+carry)%2;
               carry = (av+bv+carry)/2;
               res.insert(res.begin(), val+'0');
           }
           if(carry == 1)
             res.insert(res.begin(), '1');
           return res;
    }
};
