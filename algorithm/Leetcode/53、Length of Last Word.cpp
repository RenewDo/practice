
class Solution {
public:
    int lengthOfLastWord(string s) {
       int len = s.size()-1;
       while(len>=0 &&isspace(s[len]))
        --len;
       int last = len;
       while(len>=0 && !isspace(s[len]))
       --len;
       return last-len;
    }
};
