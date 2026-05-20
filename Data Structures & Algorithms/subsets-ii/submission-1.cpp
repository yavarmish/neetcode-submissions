class Solution {
public:
    /* 
        Time: O(n * 2^n) Space: O(n)
        Every index has the option to be picked or not, any choice would lead to a valid subset
    */
    void populateResultantSubsets(vector<int> &nums, int idx, vector<int> &validSubset, vector<vector<int>> &res) {
        res.push_back(validSubset);
        for(int i = idx; i < nums.size(); ++i) {
            if(i > idx  and nums[i] == nums[i-1]) continue;
            validSubset.push_back(nums[i]);
            populateResultantSubsets(nums, i + 1, validSubset, res);
            validSubset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> validSubset;
        sort(nums.begin(), nums.end());
        populateResultantSubsets(nums, 0, validSubset, res);
        return res;        
    }
};
