//Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         bool res = false;
         int row = -1;
         for(int i=1; i<matrix.size(); ++i)
         {
             if(target>=matrix[i-1][0] &&target<matrix[i][0])
             {
                 row = i-1;
                 break;
             }
         }
         if(row == -1)
              row = matrix.size()-1;
        
         for(int j=0; j<matrix[row].size(); ++j)
                 if(target == matrix[row][j])
                        return true;
                 
         return false;   
    }
};


//Search a 2D Matrix II

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if(matrix.empty() || target<matrix[0][0] )
                return false;
         int row = matrix.size(), col = matrix[0].size();
         int i=row-1, j=0;
         while(i>=0 && j<col)
         {
              if(matrix[i][j]==target)
                    return true;
              else if(matrix[i][j]<target)
                        j++;
              else if(matrix[i][j]>target) 
                        i--;
         } 
         return false;  
    }
};
