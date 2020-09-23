class Solution {
//DFS+ Memoization solution
//the reason for memoization works as a dp is the increasing path is a one direction path, so we don't need to concern the case when a node is visited in its subtree.
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<int> dirs={0,1,0,-1,0};
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                ans=max(dfs(matrix,dp,dirs,i,j),ans);
        }
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<int>& dirs, int i, int j){
        if(dp[i][j]>0) return dp[i][j];
        dp[i][j] = 1;
        for(int k=0;k<4;k++){
           int ni=i+dirs[k];
           int nj=j+dirs[k+1];
           if(ni>=0 && ni<matrix.size() && nj>=0 && nj<matrix[0].size() && matrix[ni][nj]>matrix[i][j])
               dp[i][j]=max(dfs(matrix,dp,dirs,ni,nj)+1,dp[i][j]);      
        }
        return dp[i][j];    
    } 
};
