
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r0=0, r2=nums.size()-1;
        for(int i=0; i<=r2;)
        {
            if(nums[i]==0)
            swap(nums[r0++], nums[i++]);
            else if(nums[i]==2)
            swap(nums[r2--], nums[i]);
            else i++;
        }
    }
};
