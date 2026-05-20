class Solution {
public:
    // Recursive Time O(n * n!) Space O(n ^ 2)
    // Using range based states Time O(n^3) Space O(n^2)
    int getMaxCoins(vector<int> &nums, int left, int right, vector<vector<int>> &maxCoinsForRange) {
        if(left > right) return 0;
        if(maxCoinsForRange[left][right] != -1) return maxCoinsForRange[left][right];
        int res = 0;
        for(int k = left; k <= right; ++k) {
            int coins = nums[left - 1] * nums[k] * nums[right + 1];
            coins += getMaxCoins(nums, left, k - 1, maxCoinsForRange);
            coins += getMaxCoins(nums,k + 1, right, maxCoinsForRange);
            res = max(res, coins);
        }
        return maxCoinsForRange[left][right] = res;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> maxCoinsForRange(n, vector<int> (n, -1));
        return getMaxCoins(nums, 1, n - 2, maxCoinsForRange);   
    }
};
