class Solution {
//1.scan through nums, from i=0 to i=nums.size(). i indicates the ending of a section
//2.print out the section if condition satisfied
public:
    string get_range(int start, int end){
       string ans = start==end?to_string(start):to_string(start)+"->"+to_string(end);
       return ans;
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long l = lower;
        for(int i = 0; i< nums.size(); i++){
            if(l < nums[i]) ans.push_back(get_range(l, min(upper,nums[i]-1)));
            l = (long)nums[i] + 1;
        }
        if(l <= upper) ans.push_back(get_range(l, upper));
        return ans;
    }
};
