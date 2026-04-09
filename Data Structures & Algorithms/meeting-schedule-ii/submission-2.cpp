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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        if(intervals.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        for(int i=0; i<intervals.size(); i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            if(!minheap.empty() && minheap.top() <= start)
                minheap.pop();
            
            minheap.push(end);
        }
        
        return minheap.size();

    }
};








































