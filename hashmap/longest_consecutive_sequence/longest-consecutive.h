/* Given an unsorted array of integers nums, return
 * the length of the longest consecutive elements
 * sequence.
 *
 * You must write an algorithm that runs in O(n) time. */


#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        int maxLongest = 0;
        unordered_map<int, int> unique;

        for (int i = 0; i < nums.size(); ++i) {
            unique[nums[i]]++;
        }

        // iterate through unique nums
        unordered_map<int, int>::iterator iter;
        iter = unique.begin();
        while (iter != unique.end()) {
            int current = iter->first;
            if (unique.find(current - 1) == unique.end()) {
                int length = 0;
                while (unique.find(current) != unique.end()) {
                    length++;
                    current++;
                }
                maxLongest = max(maxLongest, length);
            }
            iter++;
        }

        return maxLongest;
    }
};
