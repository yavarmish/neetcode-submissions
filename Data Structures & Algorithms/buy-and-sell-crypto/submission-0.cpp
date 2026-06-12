class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0, n = prices.size(), res = 0;
        while(j < n) {
            while(i < j && prices[i] > prices[j]) {
                ++i;
            }
            res = max(res, prices[j] - prices[i]);
            j++;
        }
        return res;
    }
};
