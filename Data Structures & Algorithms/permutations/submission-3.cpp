class Solution {
public:
    /*
        Time: O(n! * n) Aux. Space: O(n)
        Each index has the option to be replaced by another number or mantain it's position in any given permuation        
    */

    void populateAllPermutations(vector<int> &nums, int idx, vector<vector<int>> &res) {
        if(idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i) {
            swap(nums[idx], nums[i]);
            populateAllPermutations(nums, idx + 1, res);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        populateAllPermutations(nums, 0, res);
        return res;    
    }
};
