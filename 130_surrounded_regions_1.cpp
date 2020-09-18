class Solution {
public:
    vector<int> dirs ={0,-1,0,1,0};
    void solve(vector<vector<char>>& board) {
       for(int i=0;i<board.size();i++) {
           for(int j=0;j<board[0].size();j++)
             if((i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='O')
                dfs(board,i,j);
       }
       for(int i=0;i<board.size();i++) {
           for(int j=0;j<board[0].size();j++){
               if(board[i][j]=='O')
                   board[i][j]='X';
               else if(board[i][j]=='o')
                   board[i][j]='O';
           }
       }
        
    }
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j]='o';
        for(int k=0;k<4;k++){
            int newi=i+dirs[k];
            int newj=j+dirs[k+1];
            if(newi<0 || newi>=board.size() || newj<0 || newj>=board[0].size() || board[newi][newj]!='O')
                continue;
            dfs(board,newi,newj);
        }
        
    }
};
