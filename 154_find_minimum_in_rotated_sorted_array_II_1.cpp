class Solution {
public:
    int findMin(vector<int>& nums) {
        // r start from last element, rather than n = nums.size(), because we only need to search [0,n-1]
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] < nums[r])
                r = mid;
            else if(nums[mid] > nums[r])
                l = mid + 1;
            else
                r --;
        }
        return nums[l];
    }
};
