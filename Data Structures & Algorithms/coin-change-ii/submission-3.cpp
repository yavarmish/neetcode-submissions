class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> numWays(amount + 1, 0);
        numWays[0] = 1;

        for(int coin : coins) {
            for(int curAmount = 0; curAmount <= amount; ++curAmount) 
                if(curAmount >= coin) numWays[curAmount] += numWays[curAmount - coin];
        }
        return numWays[amount];    
    }
};
