class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=1,j=0,count=1,size=nums.size();
       if(size<1) return 0;
       for(;i<size;i++)
       {
           if(nums[j]==nums[i])
           {
               count++;
               if(count==2)
                 {
                     j++;
                     nums[j]=nums[i];
                 }
           }
           else
           {
               count=1;
               nums[++j]=nums[i];
           }
       }
       return j+1; 
    }
};

//2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     if(nums.size()<=2)
        return nums.size();
        int index = 2;
     for(int i=2; i<nums.size(); i++)
     {
          if(nums[i]!=nums[index-2])
            nums[index++]=nums[i];
     }
     return index;
    }
};
