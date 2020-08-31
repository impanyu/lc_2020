class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //mx is the max prod ending with ith element, and mn is the min prod ending with ith element
        int ans = nums[0], mx = ans, mn = ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0) swap(mx,mn);
            mx = max(nums[i]*mx, nums[i]);
            mn = min(nums[i]*mn, nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }
};
