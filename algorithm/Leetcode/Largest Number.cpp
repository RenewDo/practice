class Solution {
public:
    string largestNumber(vector<int>& nums) {
           string s;
           if(nums.empty())
                 return s;
           bool flag =false;
           for(int i=0; i<nums.size(); ++i)
           {
               flag = false;
               for(int j=1; j<nums.size()-i; ++j)
                {
                    if(catcmp(nums[j-1], nums[j]))
                    {
                        flag = true;
                        swap(nums[j-1], nums[j]);
                    }
                }
                if(flag == false)
                      break;
           }  
           if(nums[nums.size()-1] == 0)
                 return "0";
           for(int i=nums.size()-1; i>=0; --i)
                s += itos(nums[i]);
           return s;
    }
    string itos(int n)
    {
         string s;
         if(n==0)
              return "0";
         while(n != 0)
         {
             s += n%10 +'0';
             n = n/10;
         }
         int i=0, j=s.size()-1;
         while(i<j)
         {
             swap(s[i], s[j]);
             i++;
             --j;
         }
         return s;
    }
    bool catcmp(int n1, int n2)
    {
         if(((itos(n1)+itos(n2))> (itos(n2)+itos(n1))))
              return true;
         else return false;
    }
};
