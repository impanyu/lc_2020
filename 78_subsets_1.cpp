class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<vector<int>> ans;
        vector<int> out;
        dfs(nums,ans,out,0);
        return ans;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& out, int start){
        ans.push_back(out);
        for(int i = start; i < nums.size(); i++){
            out.push_back(nums[i]);
            dfs(nums,ans,out,i+1);
            out.pop_back();
        }
    }
};
