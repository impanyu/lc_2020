//the code is the same as Problem 26
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() ==0) return nums.size();
        int i = 1, j = 1;
        int count  = 1;
        for(;j<nums.size();j++){
            if(nums[j] ==nums[j-1])
                count ++;
            else
                count = 1;
            if(count<=2)
                nums[i++] = nums[j];
        }
        return i;   
    }
};
