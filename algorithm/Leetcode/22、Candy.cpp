class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> sum(ratings.size(),0);
        int base =1;
        for(int i=1; i<ratings.size(); i++)
          if(ratings[i]>ratings[i-1])
            sum[i] = max(base++, sum[i]);
          else base = 1;
         base =1;
        for(int i=ratings.size()-2; i>=0; i--)
            if(ratings[i]>ratings[i+1])
                sum[i] = max(base++, sum[i]);
            else base =1;
        return accumulate(&sum[0], &sum[0]+ratings.size(), ratings.size());
    }
};
