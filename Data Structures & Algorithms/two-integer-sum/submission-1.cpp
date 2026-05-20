class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsIdx;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int diff = target - nums[i];
            if(numsIdx.find(diff) != numsIdx.end()) return {numsIdx[diff], i};
            numsIdx[nums[i]] = i;
        }
        return {};
    }
};
