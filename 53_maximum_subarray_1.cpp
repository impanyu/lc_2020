class Solution {
//1.a linearized recursion, for each pos i, calculate the max sum of subarray ending on i.
//2. Then for each pos i, update the global maximum
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int cur_max = nums[0];
        //start from 1
        for(int i = 1; i< nums.size(); i++){
            if(cur_max < 0)
                cur_max = nums[i];
            else
                cur_max += nums[i];
            ans = max(ans, cur_max);
        }
        return ans;
  }
};
