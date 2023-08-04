/* Given an array nums of size n, return the majority element.
 *
 * The majority element is the elemtent that appears more
 * than floor(n / 2) times. You may assume that the majority
 * element always exists in the array. */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.size() / 2;
        int val;
        map<int, int> counts;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = counts.find(nums[i]);
            if (iter != counts.end()) {
                iter->second++;
            }
            else {
                counts.insert(std::make_pair(nums[i], 0));
            }
        }
        iter = counts.begin();
        for (; iter != counts.end(); ++iter) {
            if(iter->second >= majority) {
                val =  iter->first;
            }
        }
        return val;
    }
};
