//Single Number I
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res^=nums[i];
        }
        return res;
    }
};

//Single Number II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int count =0 ;
        for(int i=0; i<32; i++)
        {
            count =0;
            for(int j=0; j<nums.size(); j++)
                  count += (nums[j]>>i)&1;
            result |= (count%3)<<i;
        }
             return result;
    }
};

//Single Number III
class Solution {
private:
    int last1(int n)
    {
          int i=0;
          while(((n>>i)&1) == 0)
          {
              i++;
          }
          return i;
    }
    bool isRange(int n, int i)
    {
        if(((n>>i)&1) ==1)
            return true;
        else return false;
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
            vector<int> res;
            if(nums.size()<2)
                  return res;
            int num = 0;
            for(int i=0; i<nums.size(); ++i)
            {
                 num = num^nums[i];
            }
            int n = last1(num);
            int a=0, b=0;
            for(int j=0; j<nums.size(); ++j)
            {
                if(isRange(nums[j], n))
                {
                     a = a^nums[j];
                }
                else
                {
                     b = b^nums[j];
                }
            }
            res.push_back(a);
            res.push_back(b);
            return res;
    }
};
