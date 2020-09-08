i//refer to 154
//when it's hard to tell which side the mid is on, just r--
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] < target){
                if(nums[mid] < nums[r] && nums[r] < target)
                    r = mid;
                else if(nums[mid] == nums[r])
                    r--;
                else 
                    l = mid+1;
            }
            else {
                if(nums[mid] > nums[r] && nums[r] >= target)
                    l = mid+1;
                else if(nums[mid] == nums[r])
                    r--;
                else
                    r =mid;
            }
                
        }
        return nums.size()>0 && nums[l] == target ? true : false;
    }
};
