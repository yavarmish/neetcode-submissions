class Solution {
public:
    // Time O(n) Space O(1) Try placing every number at it's correct position(based on index)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            while(nums[i] != i + 1) {
                if(nums[i] == nums[nums[i] - 1]) return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return -1;
    }
};
