//start from index 1.
//considering the more general case of Problem 81, use a decoupled state "count" as the basis for branching statement. If use num[j] != num[j-1] directly, the code will reference modified element and thus impair the original semantics.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i = 1, j = 1;
        int count = 1;
        for(;j<nums.size();j++){
            if(nums[j] == nums[j-1])
                count++;
            else
                count = 1;
            if(count == 1)
                nums[i++] = nums[j];
        }
        return i;
    }
};

