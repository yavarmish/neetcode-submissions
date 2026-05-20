class Solution {
public:
    // Bactracking Time: O(n*(2^n)) Space: O(n)
    void populateAllSubsets(vector<int>& nums, int i, vector<int>& validSubset, vector<vector<int>>& allSubsets) {
        if(i == nums.size()) {
            allSubsets.push_back(validSubset);
            return;
        }        
        populateAllSubsets(nums, i + 1, validSubset, allSubsets);
        validSubset.push_back(nums[i]);        
        populateAllSubsets(nums, i + 1, validSubset, allSubsets);
        validSubset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> validSubset;
        vector<vector<int>> allSubsets;
        populateAllSubsets(nums, 0, validSubset, allSubsets);
        return allSubsets;        
    }

};
