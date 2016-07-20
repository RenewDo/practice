class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_gap = INT_MAX;
        int result =0;
        for(int n1=0;n1<nums.size(); n1++)
        {
            int n2 = n1+1;
            int n3 = nums.size()-1;
            while(n2<n3)
            {
               int sum = nums[n1]+nums[n2]+nums[n3];
               int gap = abs(sum- target);
               if(gap<min_gap)
               {
                   result = sum;
                   min_gap = gap;
               }
               if(sum>target)
                    n3--;
               else n2++;
            }
        }
        return result;
    }
};
