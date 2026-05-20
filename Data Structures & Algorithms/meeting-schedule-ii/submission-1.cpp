/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /*
        [1, 4] [6, 8] [7, 10] [13, 15] [19, 20]
        - Create a room for each meeting
        - Track the smallest endTime
        - If startTime(in sorted order) exceeds/matches smallest endTime we have another room available 
    */
    static bool cmp(Interval &inst1, Interval &inst2) {
        return inst1.start < inst2.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> minEndTime;
        int res = 0;
        for(Interval &interval : intervals) {
            while(minEndTime.size() and interval.start >= minEndTime.top()) {
                minEndTime.pop();
            }
            minEndTime.push(interval.end);
            res = max(res, (int)minEndTime.size());
        }
        return res;
    }
};
