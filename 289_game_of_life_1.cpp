class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int live_neis = 0;
                for(int i = -1; i<=1; i++){
                    for(int j = -1; j<=1; j++){
                        if(i == 0 && j == 0) continue;
                        int r = row + i;
                        int c = col + j;
                        if (r >=0 && r< rows && c >=0 && c<cols && (board[r][c] ==3 || board[r][c] == 1))
                           live_neis ++;
                    }
                }
                if (board[row][col] == 1 && (live_neis<2 || live_neis >3)) 
                    board[row][col] = 3;
                if(board[row][col] == 0 && live_neis==3)
                    board[row][col] = 2;
            }
        }
        
         for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == 0 || board[row][col] == 3) 
                    board[row][col] = 0;
                else
                    board[row][col] = 1;
            }
        }
        
    }
};
