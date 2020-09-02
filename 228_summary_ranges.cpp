//two pointers
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0, j = 0;
        for(;j<nums.size();j++){
            if(j == nums.size()-1 || nums[j+1] >1 + nums[j]){
                if(i == j) 
                    ans.push_back(to_string(nums[i]));
                else
                    ans.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                i = j+1;
            }
        }
        return ans;
    }
};
