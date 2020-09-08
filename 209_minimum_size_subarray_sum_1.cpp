//two pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = nums.size()+1;
        int left = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= s){
                ans = min(ans, i-left+1);
                sum -= nums[left++];
            }
        }
        return ans == nums.size()+1? 0: ans;
    }
};
