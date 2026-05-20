class Solution {
public:
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
