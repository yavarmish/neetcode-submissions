class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastMin = prices[0], res = 0;
        for(auto &price : prices) {
            if(price > lastMin) res = max(res, price - lastMin);
            if(price < lastMin) lastMin = price;
        }
        return res;
    }
};
