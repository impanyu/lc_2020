class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int num : nums){
            if(!s.count(num)) continue;
            s.erase(num);
            int l = num-1, r = num+1;
            while(s.count(l)) s.erase(l--);
            while(s.count(r)) s.erase(r++);
            ans = max(ans, r-l-2+1);
            
        }
        
        
        return ans;
    }
};
