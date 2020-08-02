//cyclic replacement, use count as the indicator for completeness
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int count = 0;
       k = k % nums.size();
       int n = nums.size();
       for(int start = 0; count < nums.size(); start++){
           int cur = start, prev = (start - k + n) % n;
           int tmp = nums[start];
           while(prev != start){
               nums[cur] = nums[prev];
               count ++;
               cur = prev;
               prev = (prev-k+n)%n;
           }
           nums[cur] = tmp;
           count++;
       }
    }
};
