class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0) return 0;
        //treat specifically using the method of 122
        if(2*k > prices.size()){
            int ans = 0;
            for(int i = 1; i < prices.size(); i++)
                ans += max(0,prices[i] - prices[i-1]);
            return ans;
        }

        //the generalization of 123
        int dp_cost[k];
        int dp_profit[k];
        for(int& cost : dp_cost)
            cost =INT_MAX;
        for(int& profit : dp_profit)
            profit = 0;
        
        for(int price : prices){
            for(int i = 0; i < k ; i++){
                if(i == 0)
                    dp_cost[i] = min(dp_cost[i],price);
                else
                    dp_cost[i] = min(dp_cost[i],price - dp_profit[i-1]);
                dp_profit[i] = max(dp_profit[i], price - dp_cost[i]);
            }
        }
        return dp_profit[k-1];
    }
};
