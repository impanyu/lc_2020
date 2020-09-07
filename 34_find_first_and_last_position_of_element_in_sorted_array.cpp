class Solution {
private:
    int binary_search(vector<int>& nums, int target, bool lower_bound){
        int l = 0, r = nums.size();
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] > target || (lower_bound && nums[mid] == target))
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int lower_bound = binary_search(nums,target,true);
        //if not found, there are two cases
        if(lower_bound == nums.size() || nums[lower_bound] != target)
            return ans;
        ans[0] = lower_bound;
        ans[1] = binary_search(nums,target,false)-1;
        return ans;
        
    }
};
