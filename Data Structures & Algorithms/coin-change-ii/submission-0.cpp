class Solution {
public:
    int countWays(int amount, vector<int> &coins, int i, vector<vector<int>> &numWays) {
        if(i == coins.size()) return 0;
        if(amount == 0) return 1;
        if(numWays[i][amount] != -1) return numWays[i][amount];
        int res = 0;
        if(coins[i] <= amount) {
            res += countWays(amount - coins[i], coins, i, numWays);
            res += countWays(amount, coins, i + 1, numWays);    
        }
        else res += countWays(amount, coins, i + 1, numWays);
        return numWays[i][amount] = res;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> numWays(n, vector<int>(amount + 1, -1));
        return countWays(amount, coins, 0, numWays);
    }
};
