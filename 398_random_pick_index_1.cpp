//reservoir sampling
class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& nums) {
        v = nums;
    }
    
    int pick(int target) {
        int cnt = 0, ans = -1;
        for(int i = 0; i< v.size();i++){
            if(v[i] != target) continue;
            cnt++;
            if(rand() % cnt == 0) ans = i;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
