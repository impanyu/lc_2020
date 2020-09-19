class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        unordered_map<int,int> cols;
        unordered_map<int,int> diags;
        unordered_map<int,int> rdiags;
        
        dfs(ans,cols,diags,rdiags,n,0);
        return ans;
    }
    
    void dfs(int& ans,
             unordered_map<int,int>& cols,
             unordered_map<int,int>& diags,
             unordered_map<int,int>& rdiags,
             int n, int row){
        if(row == n) 
            ans++;
        for(int j = 0; j < n; j++){
            if(cols[j]+diags[row-j]+rdiags[row+j] > 0)
                continue;
    
            cols[j] = 1;
            diags[row-j] = 1;
            rdiags[row+j] = 1;
            dfs(ans,cols,diags,rdiags,n,row+1);
            cols[j] = 0;
            diags[row-j] = 0;
            rdiags[row+j] = 0;
        }
    }
};

