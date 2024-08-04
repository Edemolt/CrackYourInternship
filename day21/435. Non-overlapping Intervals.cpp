class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if (intervals.empty()) return 0;

        // Sort the intervals based on the end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = intervals.size();
        int cnt = 0;
        int lastEnd = intervals[0][1]; // End time of the last added interval

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEnd) {
                // Overlap detected, need to remove this interval
                cnt++;
            } else {
                // No overlap, update lastEnd to the end time of the current interval
                lastEnd = intervals[i][1];
            }
        }

        return cnt;
    }
};