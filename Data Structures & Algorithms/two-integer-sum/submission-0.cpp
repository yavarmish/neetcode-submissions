class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsIdx;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(numsIdx.find(target - nums[i]) != numsIdx.end()) return {numsIdx[target - nums[i]], i};
            numsIdx[nums[i]] = i;
        }
        return {-1, -1};
    }
};
