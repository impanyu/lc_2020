class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_range = 0;
        for(int i = 0;i<nums.size(); i++){
            if(i > max_range) return false;
            max_range = max(nums[i]+i,max_range);
        }
        return true;
    }
};
