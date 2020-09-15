class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> ans;
        dfs(ans, out, candidates,target,0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& out, vector<int> candidates, int target, int start){
       int out_sum = accumulate(out.begin(),out.end(),0);
        if( out_sum >= target){
            if(out_sum == target)
                ans.push_back(out);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            out.push_back(candidates[i]);
            dfs(ans,out,candidates,target,i);
            out.pop_back();
        }     
    }
};
