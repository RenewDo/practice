class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> num;
        for(int i=0; i<tokens.size(); i++)
        {
             if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/" )
                   num.push(tokens[i]);
             else
             {
                  int y = stoi(num.top());
                  num.pop();
                  int x = stoi(num.top());
                  num.pop();
                  if(tokens[i]=="+")
                  x = x+y;
                  else if(tokens[i]=="-")
                  x = x-y;
                  else if(tokens[i]=="*")
                  x =x*y;
                  else if(tokens[i]=="/")
                  x =x/y;
                  num.push(to_string(x));
             }
             
        }
        return stoi(num.top());
    }
};
