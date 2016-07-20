class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  res;
        if(nums.size()<3)
            return res;
            int target =0;
            sort(nums.begin(),nums.end());
        for(int n1=0; n1<nums.size()-2; n1++)
        {
            if(n1>0 && nums[n1]==nums[n1-1]) 
                 continue;
            int n2 = n1+1;
            int n3 = nums.size()-1;
            while(n2<n3)
            {
                if(nums[n1]+nums[n2]+nums[n3]<target)
                {
                    n2++;
                    while(nums[n2-1]==nums[n2] && n2<n3)
                    n2++;
                }
                else if(nums[n1]+nums[n2]+nums[n3]>target)
                {
                    n3--;
                    while(nums[n3+1]==nums[n3]&&n2<n3)
                    n3--;
                }
                else
                {
                    vector<int>tmp;
                    tmp.push_back(nums[n1]);
                    tmp.push_back(nums[n2]);
                    tmp.push_back(nums[n3]);
                    res.push_back(tmp);
                    n2++;
                    while(nums[n2-1]==nums[n2] && n2<n3)
                    n2++;
                }
            }
        }
        return res;
    }
};
