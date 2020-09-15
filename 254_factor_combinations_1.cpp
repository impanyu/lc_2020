//back tracking with pruning
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(ans,out,n,2);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& out, int n, int start){
        if(n == 1 && out.size()>1){
            ans.push_back(out);
            return;
        }
        
        for(int i = start; i <= n; i++){
            //pruning here
            if(n % i !=0) continue;
            out.push_back(i);
            dfs(ans,out,n/i,i);
            out.pop_back();
        }      
    }
};
