class Solution {
public:
    /*
        Backtracking 
        Iterate over all the elements and pick if it's not already a part of the permutation then exclude it and continue doing the same
        Stop when current permutation has the same size as nums
    */
    void populateAllPermutations(vector<int> &nums, vector<int> &validPermuation, unordered_map<int, bool> visitedNum, vector<vector<int>>& res) {
        if(validPermuation.size() == nums.size()) {
            res.push_back(validPermuation);
            return;
        }
        for(auto &num : nums) {
            if(!visitedNum[num]) {
                visitedNum[num] = 1;
                validPermuation.push_back(num);
                populateAllPermutations(nums, validPermuation, visitedNum, res);
                validPermuation.pop_back();
                visitedNum[num] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, bool> visitedNum;
        vector<int> validPermuation;
        populateAllPermutations(nums, validPermuation, visitedNum ,res);
        return res;
    }
};
