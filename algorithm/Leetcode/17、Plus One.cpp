
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool add = false;
        for(int i=digits.size()-1; i>=0; i--)
        {
            if(i==digits.size()-1||add==true)
            {
                digits[i] += 1;
                add = false;
            }
            if(digits[i]==10)
            {
                digits[i] = 0;
                add = true;
            }
            else break;
        }
        if(add)
        {
            digits.insert(digits.begin(), 1);   
        }
        return digits;
    }
};
