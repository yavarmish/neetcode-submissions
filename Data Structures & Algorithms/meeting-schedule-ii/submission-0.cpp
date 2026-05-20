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
        2 pointers
        - Start and end times are sorted individually
        - 2 pointers are used to track the max meetings occuring at any given time
        - startTime < endTime means another room is needed, otherwise one more room is available
    */
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> startTimes, endTimes;
        int n = intervals.size();
        for(Interval &interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        int startPointer = 0, endPointer = 0, roomsRequired = 0, curRooms = 0;
        while(startPointer < n and endPointer < n) {
            if(startTimes[startPointer] < endTimes[endPointer]) {
                ++curRooms;
                ++startPointer;
                roomsRequired = max(curRooms, roomsRequired);
            }
            else {
                --curRooms;
                ++endPointer;
            }
        }
        return roomsRequired;
    }
};
