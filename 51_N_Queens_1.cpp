class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> out(n,string(n,'.'));
        unordered_map<int,int> cols;
        unordered_map<int,int> diags;
        unordered_map<int,int> rdiags;
        
        dfs(ans,out,cols,diags,rdiags,n,0);
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& out, 
             unordered_map<int,int>& cols,
             unordered_map<int,int>& diags,
             unordered_map<int,int>& rdiags,
             int n, int row){
        if(row == n) 
            ans.push_back(out);
        for(int j = 0; j < n; j++){
            if(cols[j]+diags[row-j]+rdiags[row+j] > 0)
                continue;

            out[row][j] = 'Q';
            cols[j] = 1;
            diags[row-j] = 1;
            rdiags[row+j] = 1;
            dfs(ans,out,cols,diags,rdiags,n,row+1);
            cols[j] = 0;
            diags[row-j] = 0;
            rdiags[row+j] = 0;
            out[row][j] = '.';   
        }
    }
};
