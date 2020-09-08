class Solution {
//basically the same as classical binary search, except two exceptions added
//the assumption is there's no duplicate elements in nums
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int mid=(i+j)/2;
            if(nums[mid]<target){
                if(nums[mid]<nums[j] && nums[j]<target) j=mid;//exception 1, search the other direction
                else i=mid+1;
            }
            else{
                 if(nums[mid]>nums[j] && nums[j]>=target) i=mid+1;//exception 2,search the other direction
                 else j=mid;              
            }
        }
        return nums[i] == target? i:-1;
    }
};
