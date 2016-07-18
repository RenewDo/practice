class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, len = nums.size()-1,mid = 0;
        while(i<=len)
        {
            mid = i + (len-i)/2;
            if(target == nums[mid])
                  return mid;
            if(nums[i]<=nums[mid])
            {
                if(nums[i]<=target && target < nums[mid])
                    len = mid;
                else
                    i = mid + 1;
            }
            else
            {
                if(nums[mid]<target && target <=nums[len])
                  i = mid;
                else
                  len = mid; 
            }
            
        }
        return -1;
    }
};
