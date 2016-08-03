
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char *s, const char *p){
         const char *str ,*ptr ;
         bool has = false;
         for(str =s, ptr=p; *str!='\0'; str++, ptr++)
         {
             switch(*ptr)
             {
                 case '?': break;
                 case '*':
                   while(*ptr == '*')
                     ++ptr;
                     has = true;
                    if(*ptr=='\0')
                      return true;
                    --ptr;
                    p = ptr;
                    --str;
                    s = str;
                    break;
                default:
                    if(*str!=*ptr)
                    {
                         if(!has)
                            return false;
                         s++;
                         str = s;
                         ptr = p;
                    }
                    
             }
         }
          while(*ptr=='*')
             ptr++;
        return (*ptr=='\0');
        
    }
};
