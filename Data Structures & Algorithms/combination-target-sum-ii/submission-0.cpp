class Solution {
public:
    // Optimal Backtracking Time: O(n*(2^n)) Space: O(n)
    void populateCombinations(vector<int>& candidates, int target, vector<int> &validCombination, int idx, vector<vector<int>>& resultantCombinations) {
        if(target == 0) {
            resultantCombinations.push_back(validCombination);
            return;
        }

        for(int j = idx; j < candidates.size() and candidates[j] <= target; ++j) {
            if(j > idx  and candidates[j] == candidates[j-1]) continue;
            validCombination.push_back(candidates[j]);
            populateCombinations(candidates, target - candidates[j], validCombination, j + 1, resultantCombinations);
            validCombination.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> validCombination;
        vector<vector<int>> resultantCombinations;
        populateCombinations(candidates, target, validCombination, 0, resultantCombinations);
        return resultantCombinations;        
    }
};
