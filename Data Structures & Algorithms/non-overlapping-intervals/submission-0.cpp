 class Solution {
public:
	/*
		Sorting + Greedy
		- Remove ranges with higher end time after sorting according to start time
		[a, b] [c, d] overlap if
		a < d and c < b 
	*/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end());
    	int res = 0, n = intervals.size();
    	for(int i = 0; i < n; ++i) {
    		vector<int> curInterval = intervals[i];
    		while(i < n - 1 and intervals[i + 1][0] < curInterval[1]) {
    			curInterval[1] = min(curInterval[1], intervals[i + 1][1]);
    			++res;
    			++i;
    		}
    	}
    	return res;
    }
};
