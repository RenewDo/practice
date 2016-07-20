class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        for(int i=0; i< 9; i++)
        {
            fill(used, used+9, false);
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.') 
                   continue;
                else
                {
                    if(used[board[i][j]-'1']==false)
                      used[board[i][j]-'1']=true;
                    else return false;
                }
            }
            fill(used, used+9, false);
            for(int j=0; j<9; j++)
            {
                if(board[j][i]=='.') 
                   continue;
                else
                {
                    if(used[board[j][i]-'1']==false)
                      used[board[j][i]-'1']=true;
                    else return false;
                }
            }
        }
        
        for(int i=0; i<9; i+=3)
            for(int j=0; j<9; j+=3)
            {
                fill(used, used+9, false);
                
                for(int c=i; c<i+3; c++)
                   for(int r=j; r<j+3; r++)
                   {
                        if(board[c][r]=='.') 
                            continue;
                        else
                        {
                            if(used[board[c][r]-'1']==false)
                                  used[board[c][r]-'1']=true;
                            else return false;
                         } 
                   }
            }
            return true;
    }
};
