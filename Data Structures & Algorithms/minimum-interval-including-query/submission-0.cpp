class Solution {
public:
    /*
        Time O(n * log n + m * log m)
         - Intution : Interval and queries should be used such that they are not reiterated for each query
        - Sort intevals(based on start time) and queries
        - Since we'd want to check intervals with smallest ranges first, we can use a minHeap(based on interval size) 
          and endTime(to uniquely define and determine if it's valid for query)         
    */
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        unordered_map<int, int> queryToSizeMap; // To mantain answer for each query
        int idx = 0; // To iterate over intervals
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> candidates;
        for(int &query : sortedQueries) {
            // potential candidates
            while(idx < intervals.size() and intervals[idx][0] <= query) {
                candidates.push({intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]});
                ++idx;
            }         
            // current candidate end is less than query
            while(candidates.size() and candidates.top().second < query) {
                candidates.pop();
            }
            // best answer
            if(candidates.size()) {
                pair<int, int> interval = candidates.top();                
                queryToSizeMap[query] = interval.first;
            }
            else {
                queryToSizeMap[query] = -1;
            }
        }
        vector<int> res;
        for(int &query : queries)  res.push_back(queryToSizeMap[query]);
        return res;
    }
};
