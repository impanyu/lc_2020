class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1_cost = INT_MAX, t2_cost = INT_MAX;
        int t1_profit = 0 , t2_profit = 0;
        for (int price : prices){
            t1_cost = min(t1_cost, price);
            t1_profit = max(t1_profit, price - t1_cost);
            t2_cost = min(t2_cost, price - t1_profit);
            t2_profit = max(t2_profit, price - t2_cost);
        }
        return t2_profit;
    }
};
