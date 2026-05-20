class Solution {
public:
    /*
        3 states(for profit)
        - Hold(buy)
        - Sell
        - Rest, Eat 5 star do nothing
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev_hold = -prices[0], prev_sell = 0, prev_rest = 0;

        for(int i = 1; i < n; ++i) {
            int cur_hold = max(prev_hold, prev_rest - prices[i]); // can't buy from prev_sell state, need cooldown
            int cur_sell = max(prev_sell, prices[i] + prev_hold);
            int cur_rest = max(prev_rest, prev_sell);

            prev_hold = cur_hold;
            prev_sell = cur_sell;
            prev_rest = cur_rest;
        } 
        return max(prev_sell, prev_rest);
    }
};
