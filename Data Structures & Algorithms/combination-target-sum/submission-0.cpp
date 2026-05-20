class Solution {
public:
    void populatePossibleCombinations(vector<int>& nums, int i, int target, vector<int>& validCombination, vector<vector<int>>& res) {
        if(target < 0 or i == nums.size()) return;
        else if(target == 0) {
            res.push_back(validCombination);
            return;
        }
        else {
            validCombination.push_back(nums[i]);
            populatePossibleCombinations(nums, i , target - nums[i], validCombination, res);
            validCombination.pop_back();
            populatePossibleCombinations(nums, i + 1, target, validCombination, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> validCombination;
        populatePossibleCombinations(nums, 0, target, validCombination, res);
        return res;
    }
};
