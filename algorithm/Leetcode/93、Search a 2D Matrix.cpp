class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return true;
         int  hor = matrix[0].size(), dep = matrix.size();
         int i =0, j = hor-1, i_l =0, j_l =0;
         while(i<dep && j<hor && i>=i_l && j>=j_l)
         {
              if(matrix[i][j] == target)
                  return true;
              else if(matrix[i][j] >target)
              {
                  dep = i+1;
                  j--;
              }
              else if(matrix[i][j] < target)
              {
                  i++;
                  i_l++;
              }
         }
          return false;
    }
};
