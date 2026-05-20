class Solution {
public:
    /*  
        5 6 7 1 2 3
        if there is rotation in the current bounds
        a[l] < a[m] -> mid in unrotated part
        a[l] > a[m] -> mid in rotated part

        else 
        simple binary search would work        
    */

    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid, ans = INT_MAX;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[left] > nums[mid]) {
                ans = min(ans, nums[mid]);
                right = mid;
            }
            else {
                ans = min(ans, nums[left]);
                left = mid + 1;
            }
        }
        return ans;
    }
};
