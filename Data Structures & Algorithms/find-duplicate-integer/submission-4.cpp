class Solution {
public:
    /* 
        Time O(n) Space O(1) 
        - 2 pointers cycle detection
        - Each idx should point to nums[idx], since there is a duplicate atleast 2 idxs will point to same value
    */
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int start = 0;
        while(slow != start) {
            slow = nums[slow];
            start = nums[start];
        }
        return slow;
    }
};
