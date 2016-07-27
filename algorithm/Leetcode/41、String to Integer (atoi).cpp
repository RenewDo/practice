class Solution {
public:
    int myAtoi(string str) {
        int sum=0;
        int sign =1;
        int i=0, n = str.size();
        while(i<n && str[i]==' ')
              i++;
        if(str[i]=='+')
                i++;
        else if(str[i]=='-')
        {
                 sign = -1;
                 i++;
        }
        for(; i<n; i++)
        {
              if(str[i]<'0'||str[i]>'9')
                     break;
              if(sum>INT_MAX/10 ||(sum==INT_MAX/10 && (str[i]-'0')>INT_MAX%10))
                   return sign==-1 ? INT_MIN:INT_MAX;
              sum = sum*10 + str[i]-'0';
        }
        return sum*sign;
    }
};
