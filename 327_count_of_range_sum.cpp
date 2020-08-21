// 1. binary search on multiset
// 2. the use of distance                                                                         
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ans = 0;
        long sum = 0;
        multiset<long> s;
        s.insert(sum);
        for(int num: nums){
            sum += num;
            ans += distance( s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }
        return ans;
    }
};
