class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0, len = s.size(), count = 0;
        while(i<len)
        {
            if(s[i] == ' ')
            {
                 if(i<len)
                 {
                     int j = i+1;
                     while(j<len && s[j]==' ')j++;
                     if(j>=len)
                         return count;
                     else  count = 0;
                 }
            }
            else
                count++;
            i++;
        }
        return count;
    }
};
