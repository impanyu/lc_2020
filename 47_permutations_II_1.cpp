class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        dfs(ans,nums,0);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int> nums, int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size();i++){
            if(i>start && nums[i] == nums[start]) continue;
            swap(nums[i],nums[start]);
            dfs(ans,nums,start+1);
            //swap(nums[i],nums[start]);
        }
    }
};
