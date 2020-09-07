class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> r_elements;
        for(int i = nums.size()-1; i>=0; i--){
            //l is the lower bound of nums[i], or the number of elements in r_elements which are smaller than nums[i]
            auto l = lower_bound(r_elements.begin(),r_elements.end(),nums[i]);
            ans[i] = l - r_elements.begin();
            r_elements.insert(l,nums[i]);
        }
        return ans;
    }
};
