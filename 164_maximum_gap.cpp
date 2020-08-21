// bucket_size must larger than 0
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = nums.size();
        for(int num : nums){
            mx = max(mx,num);
            mn = min(mn,num);
        }
        int bucket_size = (mx - mn)/(n-1);
        bucket_size = max(1, bucket_size);
        int bucket_num = (mx-mn)/bucket_size+1;
        vector<int> bucket_mins(bucket_num, INT_MAX);
        vector<int> bucket_maxs(bucket_num, INT_MIN);
        set<int> bucket_occupied;
        for(int num : nums){
            int idx = (num - mn)/bucket_size;
            bucket_mins[idx] = min(num, bucket_mins[idx]);
            bucket_maxs[idx] = max(num, bucket_maxs[idx]);
            bucket_occupied.insert(idx);
        }
        int pre = 0;
        int ans = 0;
        for(int i = 1; i < bucket_num; i++){
            if(!bucket_occupied.count(i)) continue;
            ans = max(ans, bucket_mins[i] - bucket_maxs[pre]);
            pre = i;
        }
        return ans;
        
    }
};
