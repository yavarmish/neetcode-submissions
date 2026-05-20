class Solution {
public:    
    // Bottom up space optimized Time O(n) Space O(1)
    int climbStairs(int n) {
        int prev1 = 1, prev2 =1, res = 1;
        for(int i = 2; i <= n; ++i) {
            res = prev1 + prev2;
            prev2 = prev1;
            prev1 = res;
        } 
        return res;
    }
};
