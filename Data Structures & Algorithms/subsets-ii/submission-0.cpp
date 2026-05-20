class Solution {
public:
    void populateResultantSubsets(vector<int> &nums, int idx, vector<int> &curSubset, vector<vector<int>> &res) {
        res.push_back(curSubset);
        for(int i = idx; i < nums.size(); ++i) {
            if(i > idx  and nums[i] == nums[i-1]) continue;
            curSubset.push_back(nums[i]);
            populateResultantSubsets(nums, i + 1, curSubset, res);
            curSubset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curSubset;
        sort(nums.begin(), nums.end());
        populateResultantSubsets(nums, 0, curSubset, res);
        return res;        
    }
};
