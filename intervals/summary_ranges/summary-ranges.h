/* You are given a sorted unique integer array nums.
 *
 * A range [a,b] is the set of all integers from a
 * to b (inclusive). 
 *
 * Return the smallest sorted list of ranges that
 * cover all the numbers in the array exactly. That
 * is, each elements of nums is covered by exactly
 * one of the ranges, and there is no integer x
 * such that x is in one of the ranges but not in
 * nums.
 *
 * Each range [a, b] in the list should be output as:
 * "a->b" if a != b
 * "a" if a == b*/ 

/* *** WE ARE RETURN ALL RANGES *** */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int s = 0, e = 0, size = nums.size();
        vector<string> strRanges;

        while (e < size) {
            if (e < size - 1 && nums[e+1] != nums[e]+1) {
                strRanges.push_back(rangeToStr(nums[s], nums[e]));
                e++;
                s = e;
            } else if (e == size - 1) { // at end, push range no matter what
                strRanges.push_back(rangeToStr(nums[s], nums[e]));
                e++;
            }
            else {
                e++;
            }
        }

        return strRanges;
    }
private:
    string rangeToStr(int s, int e) {
        string rts = to_string(s);
        if (s != e) {
            rts += "->";
            rts += to_string(e);
        }
        return rts;
    }
};

