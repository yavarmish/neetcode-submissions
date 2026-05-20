class Solution {
public:
    /*  
        Binary Search : Time O(n) Space O(1)
        5 6 7 1 2 3
        a[l] < a[m] -> mid in unrotated part        
        a[l] > a[m] -> mid in rotated part
   
    */

    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid, ans = INT_MAX;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[left] > nums[mid]) {
                ans = min(ans, nums[mid]);
                right = mid - 1;
            }
            else {
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
        }
        return ans;
    }
};
