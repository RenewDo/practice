class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        string longest = s.substr(0,1);
        for(int i=0; i<s.size(); i++)
        {
            string tmp = findPali(s, i, i);
            if(tmp.size()>longest.size())
               longest = tmp;
            tmp = findPali(s, i, i+1);
            if(tmp.size()>longest.size())
               longest = tmp;
        }
        return longest;
    }
private:
    string findPali(string s, int i, int j)
    {
        int a = i, b = j;
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
        return s.substr( i+1, j-i-1);
    }
};


//Manacher
class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.empty())
            return "";
        string str = change(s);
        vector<int> p(str.size(),0);
        int maxv=0, id = 0; 
        for(int i=1; i<str.size()-1; i++)
        {
            int i_mirr = id*2 - i;
            p[i] = maxv>i? min(maxv-i, p[i_mirr]):0;
            while(str[i-1-p[i]]==str[i+1+p[i]])
               p[i]++;
            if(p[i]+i>maxv)
            {
                maxv = p[i] +i;
                id = i;
            }
        }
        int maxlen =0;
        int center_id=0;
        for(int i=1; i<str.size()-1; i++)
        {
            if(maxlen<p[i])
            {
                maxlen = p[i];
                center_id = i;
            }
        }
        return s.substr((center_id-maxlen-1)/2,maxlen);
    }
private:
    string change(string s)
    {
        string res = "^";
        for(int i=0; i<s.size(); i++)
        {
            res += "#" + s.substr(i,1);
        }
        res += "#$";
        return res;
    }
};
