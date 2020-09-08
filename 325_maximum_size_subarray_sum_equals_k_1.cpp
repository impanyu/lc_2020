//variant of two sum
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m; //map sum -> index
        m[0] = 0;
        int ans = 0;
        vector<int> sums(nums.size()+1,0);
        for(int i = 1; i <= nums.size(); i++)
            sums[i] = sums[i-1] + nums[i-1];
        for(int i = 1; i<=nums.size(); i++){
            if(m.count(sums[i] - k)) ans = max(ans, i - m[sums[i]-k]);
            if(!m.count(sums[i])) m[sums[i]] = i;
        }    
        return ans;
    }
};
