class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> numWays(n + 1, vector<int>(amount + 1, 0));
        int res = 0;
        for(int i = 0; i <= n; ++i) numWays[i][0] = 1;

        for(int i = n - 1; i >= 0; --i) {
            for(int curAmount = 0; curAmount <= amount; ++curAmount) {
                if(curAmount >= coins[i]) {
                    numWays[i][curAmount] += numWays[i][curAmount - coins[i]];
                    numWays[i][curAmount] += numWays[i + 1][curAmount];
                }
            }
        }
        return numWays[0][amount];
    }
};
