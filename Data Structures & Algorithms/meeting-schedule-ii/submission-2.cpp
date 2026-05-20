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
        Line Sweep:
        - We want to know the max meetings at any given time
        - Number of ongoing meetings only change when a new start or end time is encountered
    */
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> meetingTimes;
        for(auto &interval : intervals) {
            ++meetingTimes[interval.start];
            --meetingTimes[interval.end];
        }
        int count = 0, maxCount = 0;
        for(auto &[time, occurence] : meetingTimes) {
            count += occurence;
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};
