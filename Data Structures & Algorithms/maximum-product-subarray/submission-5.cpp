class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Kadane's algo [Mantain CurMax and CurMin]
        int curMax = 1, curMin = 1, res = INT_MIN;
        for(auto &num : nums) {
            /* 
            -ve num swaps inequality 
            eg. curMax = 8 curMin = 2 num = -3
            swapped -> curMax = 2 * -3 and curMin = 8 * -3
            */
            if(num < 0) swap(curMax, curMin);
            // update and reset if required
            curMax = max(num, curMax * num);
            curMin = min(num, curMin * num);
            res = max(curMax, res);
        }
        return res;
    }
};
