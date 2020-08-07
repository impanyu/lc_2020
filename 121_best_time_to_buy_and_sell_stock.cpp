class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_min  = INT_MAX;
        int ans = 0;
        for(int price: prices){
            current_min = min(current_min, price);        
            int profit = price - current_min;
            ans = max(ans,profit);
        }
        return ans;
    }
};
