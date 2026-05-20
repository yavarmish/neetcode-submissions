class Solution {
public:
    int findMin(vector<int> &nums) {
        /*  
            Converge towards the highest number while updating result : Time O(log(n)) Space O(1)
            5 6 7 1 2 3
        */
        // int left = 0, right = nums.size() - 1, mid, minNum = INT_MAX;
        // while(left <= right) {
        //     mid = left + (right - left) / 2;
        //     if(nums[left] > nums[mid]) {
        //         minNum = min(minNum, nums[mid]);
        //         right = mid - 1;
        //     }
        //     else {
        //         minNum = min(minNum, nums[left]);
        //         left = mid + 1;
        //     }
        // }
        // return minNum;

        /*  
            Converge towards the pivot(smallest number) : Time O(log(n)) Space O(1)
            5 6 7 8 9 1 2 3
            7 8 9 1 2 3 5 6            
        */
        int left = 0, right = nums.size() - 1, mid;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }

};
