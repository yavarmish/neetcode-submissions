class Solution {
public:
     /*
        Backtracking 
        Iterate over all the elements and pick if it's not already a part of the permutation then exclude it and continue doing the same
        Stop when current permutation has the same size as nums
    */
    void populateAllPermutations(vector<int> &nums, vector<int> &validPermuation, vector<bool> &visitedIndexes, vector<vector<int>>& res) {
        if(validPermuation.size() == nums.size()) {
            res.push_back(validPermuation);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(!visitedIndexes[i]) {
                visitedIndexes[i] = 1;
                validPermuation.push_back(nums[i]);
                populateAllPermutations(nums, validPermuation, visitedIndexes, res);
                validPermuation.pop_back();
                visitedIndexes[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visitedIndexes(nums.size(), false);
        vector<int> validPermuation;
        populateAllPermutations(nums, validPermuation, visitedIndexes ,res);
        return res;
    }
};
