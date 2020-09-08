class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int contains_one = 0;
        for(int value: nums){
            if(value == 1)
                contains_one = 1;
        }
        if(!contains_one) return 1;
        
        for(int i =0; i<n; i++){
            if(nums[i]<=0 || nums[i]>n)
                nums[i] = 1;
        }
        
        //pay attention to the use of two abs
        for(int i=0; i<n;i++){
            int index = abs(nums[i])-1;
            nums[index] = -abs(nums[index]);
        }
        
        for(int i=0; i<n;i++){
            if(nums[i]>0)
                return i+1;
        }
        return n+1;
    }
};

