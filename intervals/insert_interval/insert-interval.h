 /* You are given an array of non-overlapping intervals
  * intervals where intervals[i] = [start_i, end_i] 
  * represent the start and the end of the ith interval
  * and intervals is sorted in ascending order by start_i.
  * You are also given an interval newInterval = [start, end]
  * that represents the start and end of another interval.
  *
  * Insert newInterval into intervals such that intervals
  * is still sorted in ascending order by start_i and
  * intervals still does not have any overlapping intervals
  * (merge overlapping intervals if necessary).
  *
  * Return intervals after the insertion. */


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
    }

private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if (intervals.empty())
            return merged;

        vector<int> curr_merged = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= curr_merged[1]) {
                curr_merged[1] = max(curr_merged[1], intervals[i][1]);
            } else {
                merged.push_back(curr_merged);
                curr_merged = intervals[i];
            }
        }

        merged.push_back(curr_merged);

        return merged;
    }
};
