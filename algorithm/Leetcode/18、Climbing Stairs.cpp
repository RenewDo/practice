class Solution {
public:
    int climbStairs(int n) {
        int res=1;
        int pre =0;
        for(int i=0; i<n; i++)
        {
            int tmp = res;
            res += pre;
            pre = tmp;
        }
        return res;
    }
};
