class Solution {
public:
    int trap(vector<int>& height) {
        int max =0;
        for(int i=0; i<height.size(); i++)
            if(height[i]>height[max])
                max = i;
        int edg=0;
        int water=0;
        for(int j=0; j<max; j++)
           if(height[j]>edg)
                edg = height[j];
            else water += edg-height[j];
        edg=0;
        for(int j=height.size()-1; j>max; --j)
            if(height[j]>edg)
                edg = height[j];
            else water += edg-height[j];
        return water;
    }
};
