class Solution {
    int total = 0;
public:

    int countWays(vector<int> &nums, int i, int curSum, int &target, vector<vector<int>> & numWays) {
        if(curSum == target and i == nums.size()) return 1;
        if(i == nums.size()) return 0;
        if(numWays[i][curSum + total] != -1) return numWays[i][curSum + total];

        return numWays[i][curSum + total] = countWays(nums, i + 1, curSum + nums[i], target, numWays) + countWays(nums, i + 1, curSum - nums[i], target, numWays);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> numWays(n, vector<int>(2 * total + 1, -1));
        return countWays(nums, 0, 0, target, numWays); 
    }
};
