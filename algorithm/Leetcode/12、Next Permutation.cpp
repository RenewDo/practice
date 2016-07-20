class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n1 = nums.size()-2,n2=nums.size()-1;
         while(n1>0)
         {
             if(nums[n1]<nums[n1+1])
                  break;
             else n1--;
         }
         while(n2>n1)
         {
             if(nums[n2]>nums[n1])
             break;
             else n2--;
         }
         swap(nums[n1], nums[n2]);
         int i=n1+1;
         int j=nums.size()-1;
         while(i<j && i>0)
         {
             swap(nums[i], nums[j]);
             i++;
             j--;
         }
    }
};
