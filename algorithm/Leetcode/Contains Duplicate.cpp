//Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            times[nums[i]]++;
            if(times[nums[i]]>1)
            return true;
        }
        return false;
    }
private:
 unordered_map<int, int> times;
};

//Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len<1 || k<1)
               return false;
        for(int i=0; i<len; i++)
        {
            if(times[nums[i]] == 0)
                   times[nums[i]] = i+1;
            else
            {
                if(i+1-times[nums[i]] <= k)
                      return true;
                else times[nums[i]] = i+1;
            }
        }
        return false;
    }

private:
     unordered_map<int, int> times;
};


//Contains Duplicate III
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long, long>> res;
        for(int i=0; i<nums.size(); i++)
              res.push_back(make_pair(nums[i],i));
              
        sort(res.begin(), res.end());
        
        for(int j=0; j<nums.size(); j++)
        {
            int most = j+1;
            while(most<nums.size() && res[most].first-res[j].first<=t)
            {
                if(abs(res[most].second-res[j].second) <= k)
                       return true;
                most++;
            }
                    
        }
    return false;        
    }
};
