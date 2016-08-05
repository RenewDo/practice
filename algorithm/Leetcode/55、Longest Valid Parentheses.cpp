class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> in;
        int max_len =0, last =-1;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='(')
              in.push(i);
            else
            {
                 if(in.empty())
                    last = i;
                 else
                 {
                     in.pop();
                     if(in.empty())
                          max_len = max(max_len, i-last);
                     else max_len = max(max_len, i-in.top());
                 }
            }
        }
        return max_len;
    }
};
