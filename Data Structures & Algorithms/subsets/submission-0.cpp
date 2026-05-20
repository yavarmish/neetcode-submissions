class Solution {
public:
    // Recursion Time: O(n*(2^n)) 
    void populateAllSubsets(vector<int>& nums, int i, vector<int> validSubset, vector<vector<int>>& allSubsets) {
        if(i == nums.size()) {
            allSubsets.push_back(validSubset);
            return;
        }
        populateAllSubsets(nums, i + 1, validSubset, allSubsets);
        validSubset.push_back(nums[i]);
        populateAllSubsets(nums, i + 1, validSubset, allSubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        populateAllSubsets(nums, 0, {}, allSubsets);
        return allSubsets;        
    }

};
