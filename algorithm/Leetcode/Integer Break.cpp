class Solution {
public:
    int integerBreak(int n) {
        vector<int> res(n+1,0);
        res[1]=1;
        res[2]=1;
        for(int i=3; i<=n; i++)
        {
			for(int j=1; j<i; j++)
            res[i] = max(j*res[i-j],max(res[i],j*(i-j)));
        }
        return res[n];
    }
};
