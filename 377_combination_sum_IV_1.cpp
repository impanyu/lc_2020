//The problem is, the combinations from 1 to target could be too large to be represent by any number type. The unsigned int or any unsigned type just automatically overflow to modulo "type max value". For example, unsigned int x = 4294967295 is ok but after do x += 1 operation, x will be 0 without any runtime error.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            
            for(auto n : nums){
                if(i>=n)
                    dp[i] += dp[i-n];
            }
        }
        return dp.back();
    }
};
