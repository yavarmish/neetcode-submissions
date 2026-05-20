class Solution {
public:
    /*
        Time O(n) Space O(n)
        Based on overlap
        [a , b] [c , d]
        Overlap : a <= d and c <= b (for any 2 intervals)
        No overlap : c > b or a > d (here since a <= c we do not need a > d)
    */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        // no overlap
        while(i < n and newInterval[0] > intervals[i][1]) {
            res.push_back(intervals[i]);
            ++i;
        }
        // merge overlapping intervals, intevals[i][1] <= newInterval[0] already checked due to no overlap
        while(i < n and intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);
        // add other intervals 
        while(i < n) {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};
