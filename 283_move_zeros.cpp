class Solution {
//two pointers i, j, propelled by faster pointer j. 
//all elements before i is non zero
//only swap when nums[j]!=0
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 , j = 0;
        for(;j < nums.size(); j++){
            if(nums[j] != 0)
                swap(nums[i++],nums[j]);
        }
    }
};
