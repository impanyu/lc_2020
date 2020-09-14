class Solution {
public:
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(ans,out,n,k,1);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& out, int n, int k, int start){
        if(out.size() == k)
            ans.push_back(out);
        for(int i = start; i <= n; i++){
            out.push_back(i);
            dfs(ans,out,n,k,i+1);
            out.pop_back();
        }  
    }
};
