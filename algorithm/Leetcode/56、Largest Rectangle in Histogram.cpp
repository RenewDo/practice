class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> up;
        heights.push_back(0);
        int res =0;
        for(int i=0; i<heights.size();i++)
        {
            if(up.empty()|| (!up.empty()&&heights[i]>heights[up.top()]))
              up.push(i);
            else 
            {
                 while(!up.empty() && heights[i]<heights[up.top()])
                 {
                         int tmp = up.top();
                         up.pop();
                        res = max(res, heights[tmp]*(up.empty()? i:i-up.top()-1));
                 }
                 up.push(i);
            }
        }
        return res;
    }
};
