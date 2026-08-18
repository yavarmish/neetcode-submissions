class Solution {
public:
    /*
        Monotonically decreasing deque
        [2,5,1,3,7,4,8] k = 3

        [2] -> [5] -> [1,5] ans = [5]
        back front
         |   |
        [3,1,5]             ans = [5, 5]
        [7]                 ans = [5,5,7]
        [4,7]               ans = [5,5,7,7]
        [8]                 ans = [5,5,7,7,8]

        while(nums[j] > q.back()) q.pop_back()
        if(q.front() == nums[i]) q.pop_front()

        DP -> more intutive -> mantain leftMax and rightMax(reset for new window)
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxWindow;
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> maxElements;
        while(j < n) {
            while(maxWindow.size() and nums[j] > maxWindow.back()) {
                maxWindow.pop_back();                
            }
            maxWindow.push_back(nums[j]);
            if(j < k) ++j;
            else {
                if(maxWindow.front() == nums[i]) maxWindow.pop_front();
                ++i;
                ++j;
            }
            if(j >= k) maxElements.push_back(maxWindow.front());
        }
        return maxElements;
    }
};
