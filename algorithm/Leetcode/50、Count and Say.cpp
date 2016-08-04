class Solution {
public:
    string countAndSay(int n) {
        string res("1");
        while(--n)
        res = next(res);
        return res;
    }
    string next(string s)
    {
        string res;
        char tmp = s[0];
        int count =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=tmp)
            {
                res += (count+'0');
                res+= tmp;
                count = 1;
                tmp = s[i];
            }
            else count++;
        }
        res += (count+'0');
         res+= tmp;
        return res;
    }
};
