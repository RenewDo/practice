class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)
            return res;
        sort(nums.begin(), nums.end());
        unordered_multimap<int, pair<int, int>> twsm;
        for(int i=0; i<nums.size()-1; i++)
            for(int j=i+1; j<nums.size(); j++)
            {
                int tmp = nums[i]+nums[j];
                twsm.insert(make_pair(tmp, make_pair(i,j)));
            }
        
        for(auto i=twsm.begin(); i!=twsm.end(); i++)
        {
            int gap = target-i->first;
            auto range= twsm.equal_range(gap);
            for(auto j=range.first; j!=range.second; j++)
            {
                int n1= i->second.first;
                int n2 = i->second.second;
                int n3 = j->second.first;
                int n4 = j->second.second;
                if(n1!=n3 && n1!=n4 && n2!=n3 && n2!=n4)
                {
                    vector<int> tmp1;
					tmp1.push_back(nums[n1]);
					tmp1.push_back(nums[n2]);
					tmp1.push_back(nums[n3]);
					tmp1.push_back(nums[n4]);
                    sort(tmp1.begin(), tmp1.end());
                    res.push_back(tmp1);
                }
                
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
