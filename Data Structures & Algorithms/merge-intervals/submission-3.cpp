class Solution {
public:
    /*
        Time O(n * log n) Space O(n)
        For 2 intervals [a, b] and [c, d] to overlap
        a <= d and c <= b
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i = 0; i < n; ++i) {
            vector<int> newInterval = intervals[i];
            while(i < n - 1 and newInterval[0] <= intervals[i + 1][1] and intervals[i + 1][0] <= newInterval[1]) {
                newInterval[0] = min(newInterval[0], intervals[i + 1][0]);
                newInterval[1] = max(newInterval[1], intervals[i + 1][1]);
                ++i;
            }
            res.push_back(newInterval);
        }
        return res;
    }
};
