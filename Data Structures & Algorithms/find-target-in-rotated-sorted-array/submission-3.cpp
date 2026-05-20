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
        int left = 0, n = nums.size(), right = n - 1, mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]) {
                if(target < nums[left] or target > nums[mid])
                    left = mid + 1;
                else right = mid - 1;
            }
            else {
                if(target < nums[mid] or target > nums[right])
                    right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
