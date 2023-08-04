/*  Given an array of intervals where 
 *      intervals[i] = [start_i, end_i],
 *  merge all overlapping intervals, and return an array
 *  of the non-overlapping intervals that cover all the
 *  intervals in the input. */


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        if (intervals.empty())
            return merged;
        
        sort(intervals.begin(), intervals.end());

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
