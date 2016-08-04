class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> s;
        for(auto i:strs)
        {
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            s[tmp].push_back(i);
        }
        unordered_map<string,vector<string>>::iterator it;
        vector<vector<string>> res;
        for(it=s.begin(); it!=s.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};
