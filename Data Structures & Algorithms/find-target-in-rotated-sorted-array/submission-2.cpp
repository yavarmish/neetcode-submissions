class Solution {
public:
    // 7 8 9 2 3 5
    int getPivot(vector<int> & nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else right = mid;
        }
        return left;
    }
    int search(vector<int>& nums, int target) {
        // Find Pivot and binary search on each part Time: O(logn) Space: O(1)
        int minElementIdx = getPivot(nums), n = nums.size(), idx;   
        idx = lower_bound(nums.begin(), nums.begin() + minElementIdx, target) - nums.begin();        
        if(idx != n and nums[idx] == target) return idx;
        idx = lower_bound(nums.begin() + minElementIdx, nums.end(), target) - nums.begin();        
        return idx == n or nums[idx] != target ? -1 : idx;
    }
};
