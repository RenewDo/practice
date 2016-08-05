class Solution {
public:
    bool isValid(string s) {
        bool res=true;
        stack<char>in;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
             in.push(s[i]);
            else
            {
                if(in.empty())
                  return false;
                 char tmp = in.top();
                 in.pop();
                switch(s[i])
                {
                    case ')':
                       if(tmp=='(')
                       break;
                       else return false;
                    case ']':
                       if(tmp=='[')
                       break;
                       else return false; 
                     case '}':
                       if(tmp=='{')
                       break;
                       else return false;
                }
            }
        }
        if(!in.empty())
           return false;
        else return res;
    }
};
