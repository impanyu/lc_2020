class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, held = INT_MIN, reset = 0;
        for(int price : prices){
            int pre_sold = sold;
            sold = held + price;
            held = max(held, reset - price);
            reset = max(reset, pre_sold);
        }
        return max(sold,reset);        
    }
};
