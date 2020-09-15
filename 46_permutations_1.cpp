class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {   
        vector<vector<int>> ans;
        dfs(ans,nums,0);
        return ans;
    }   
    
    void dfs(vector<vector<int>>& ans, vector<int>& nums, int start){
        if(start == nums.size())
            ans.push_back(nums);
        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]);
            dfs(ans,nums,start+1);//different from combination, here is start+1, not i+1
            swap(nums[start], nums[i]); 
        }
    }
    
};
