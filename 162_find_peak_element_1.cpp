class Solution {
public:
    // for nums[i]>nums[i+1]
    // false false false true true true
    // find the first i s.t it is true
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<r){
            int mid = l+ (r-l)/2;
            if(nums[mid]>nums[mid+1]) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
