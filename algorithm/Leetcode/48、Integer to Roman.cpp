class Solution {
public:
    string intToRoman(int num) {
        const int intn[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string roman[]= {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res="";
        for(int i=0;num>0 ; i++)
        {
              int count = num / intn[i];
              num = num % intn[i];
              for(; count>0; count--)
              {
                    res += roman[i];
              }
        }
        return res;
    }
};
