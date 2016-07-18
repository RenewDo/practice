class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,sz=nums.size();
        if(sz==0) return 0;
        for(i=1;i<sz; )
        {
            if(nums[i]==nums[j])
            {
               i++;  
            }
            else
            {
                j++;
                nums[j]=nums[i];
                i++;
            }
        }
        return j+1;
    }
};
