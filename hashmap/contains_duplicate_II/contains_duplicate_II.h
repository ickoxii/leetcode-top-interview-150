/* Given an integer array nums and an integer k,
 * return true if there are two distinct indices
 * i and j in the array such that nums[i]==nums[j]
 * and abs(i-j) <= k. */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> uniqueNums;

        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int>::iterator iter;
            iter = uniqueNums.find(nums[i]);
            if (iter != uniqueNums.end()) {
                // duplicate condition
                if (abs(iter->second - i) <= k) {
                    return true;
                } 
                else { // update the latest index
                    uniqueNums[nums[i]] = i;
                }
            }
            else {
                uniqueNums[nums[i]] = i;
            }
        }

        return false;
    }
};
