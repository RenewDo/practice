class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.reserve(1<<n);
        res.push_back(0);
        for(int i=0; i<n; i++)
        {
             int high = 1<<i;
             for(int j=res.size()-1; j>=0; j--)
             res.push_back(high|res[j]);
        }
        return res;
    }
};
