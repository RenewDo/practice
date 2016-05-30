//Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        if(nums.empty())
               return output;
        int left=1, right=1;
        for(int i=0; i<nums.size(); i++)
        {
            output[i] = left;
            left = left * nums[i];
        }
        for(int i=nums.size()-1; i>=0; i--)
        {
            output[i] = right * output[i];
            right = right * nums[i];            
        }
        
        return output;
    }
};

//Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> local(nums.size(), 0);    
        vector<int> global(nums.size(), 0);
        local[0]= nums[0];
        global[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            local[i] = max(local[i-1]+nums[i], nums[i]);
            global[i] = max(local[i], global[i-1]);
        }
        
        return global[nums.size()-1];
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int sum = 0;
        int maxsum =nums[0];
        for(int i=0; i<nums.size(); ++i)
        {
             if(nums[i]+sum< nums[i])
                  sum = 0;
             sum += nums[i];
             if(maxsum < sum)
                  maxsum = sum;
             
        }
       return maxsum;
    }
};

//Maximum Product Subarray
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
             return 0;
        int max_l = nums[0];
        int min_l = nums[0];
        int max_g = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            int tmp_max = max_l;
            max_l = max(max(tmp_max*nums[i], nums[i]), min_l*nums[i]);
            min_l = min(min(tmp_max*nums[i], nums[i]), min_l*nums[i]);
            max_g = max(max_g, max_l);
        }
        return max_g;
    }
};
