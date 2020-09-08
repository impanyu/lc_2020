class Solution {
private:
   int b_search(vector<int>& dp, int num){
       int l = 0 , r = dp.size();
       while( l < r ){
           int mid = l + (r-l)/2;
           if(dp[mid] >= num)
               r = mid;
           else
               l = mid+1;
       }
       return l;
   }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(auto num : nums){
            int insertion_index = b_search(dp,num);
            if(insertion_index == dp.size()) 
                dp.push_back(num);
            else
                dp[insertion_index] = num;
        }
        return dp.size();
    }
};
