class Solution {
public:
    // Kadane's algo mantaining maxProd and minProd(for -ve values)
    int maxProduct(vector<int>& nums) {
        int c = 1, maxProd = 1, minProd = 1, res = INT_MIN, n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0) swap(maxProd, minProd);
            maxProd = max(maxProd * nums[i], nums[i]);
            minProd = min(minProd * nums[i], nums[i]);
            res = max(maxProd, res);
        }
        return res;
    }
};
