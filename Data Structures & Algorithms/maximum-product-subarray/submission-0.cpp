class Solution {
public:
    // Prefix and suffix product for each index Time O(n) Space O(1)
    int maxProduct(vector<int>& nums) {
        int preProduct = 1, sufProduct = 1, n = nums.size(), res = INT_MIN;
        for(int i = 0; i < n; ++i) {
            preProduct = nums[i] * (preProduct == 0 ? 1 : preProduct);
            sufProduct = nums[n - i - 1] * (sufProduct == 0 ? 1 : sufProduct);
            res = max(res, max(preProduct, sufProduct));
        }
        return res;
    }
};
