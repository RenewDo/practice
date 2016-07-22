class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int n = sizeof(int)*8;
        vector<int> count(n, 0);
        for(int i=0; i<len; i++)
           for(int j=0; j<n; j++)
           {
               count[j] += (nums[i]>>j)&1;
               count[j] = count[j]%3;
           }
        int res = 0;
        for(int i=0; i<n; i++)
          res +=(count[i]<<i);
        return res;
    }
};
