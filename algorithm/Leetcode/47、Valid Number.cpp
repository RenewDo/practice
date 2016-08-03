class Solution {
public:
    bool isNumber(string s) {
         if(s.empty())
            return false;
         bool res = false, e = false, dot= false;
         int i=0, len = s.size()-1;
         while(i<=len && isspace(s[i]))
         i++;
         while(i<=len && isspace(s[len]))
         len--;
         if(i<=len &&(s[i]=='+'||s[i]=='-'))
           i++;
         if(i<=len && (isdigit(s[i])||s[i]=='.'))
         {
             if(s[i]=='.')
             {
                 if(i<=len-1 && isdigit(s[i+1]))
                 {
                     dot = true;
                     i= i+2;
                 }
                 else return false;
             }
             else i++;
             while(i<=len)
             {
                 if(isdigit(s[i]))
                 {
                     i++;
                     continue;
                 }
                 else if(!dot && !e && s[i]=='.')
                         {
                            dot = true;
                            i++;  
                         }
                          
                 else if(!e && (s[i]=='e'||s[i]=='E'))
                 {
                     if(i<=len-1 && isdigit(s[i+1]))
                     {
                          e = true;
                          i = i+2; 
                     }
                     else  if(i<=len-2 &&(s[i+1]=='-'||s[i+1]=='+') &&isdigit(s[i+2]))
                     {
                         e = true;
                         i = i+3;
                     }
                     else return false;
                 }
                 else return false;
             }
             return true;
         }
         else return false;
    }
};
