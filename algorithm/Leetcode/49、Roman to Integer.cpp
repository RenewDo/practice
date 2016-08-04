class Solution {
public:
    int romanToInt(string s) {
     unordered_map<char,int> rtoi;
     rtoi['I']=1;
     rtoi['V']=5;
     rtoi['X']=10;
     rtoi['L']=50;
     rtoi['C']=100;
     rtoi['D']=500;
     rtoi['M']=1000;
     int res =0;
     for(int i=0; i<s.size(); i++)
     {
         if(i>0 && rtoi[s[i]]>rtoi[s[i-1]])
          res += (rtoi[s[i]]-2*rtoi[s[i-1]]);
         else res += rtoi[s[i]];
     }
      return res;
    }
};
