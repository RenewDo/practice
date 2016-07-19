class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for(auto i :nums) used[i] = false;
        int longest = 1;
        for(auto i:nums)
        {
            if(used[i]) continue;
            used[i] = true;
            int len =1;
            for(auto j=i+1;used.find(j)!=used.end();++j)
            {
                len++;
                used[j]=true;
            }
               
            for(auto j=i-1; used.find(j)!=used.end(); --j)
            {
                len++;
                used[j]=true;
            }
            longest = max(len, longest);
        }
        return longest;
        
    }
};
