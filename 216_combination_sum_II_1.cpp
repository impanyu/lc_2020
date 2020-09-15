class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> out;
        dfs(ans,out,k,n,1);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& out, int k, int n, int start){      
        if(out.size() == k){
            int out_sum = accumulate(out.begin(),out.end(),0);
            if(out_sum == n)
                ans.push_back(out);
            return;
        }
        for(int i = start; i <= 9; i++){
            out.push_back(i);
            dfs(ans,out,k,n,i+1);
            out.pop_back();
        }   
    }
};
