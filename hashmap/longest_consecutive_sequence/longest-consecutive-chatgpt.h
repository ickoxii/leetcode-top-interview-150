// uses unordered_set instead of unordered_map
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;

        // Add all elements to the set
        for (int num : nums) {
            numSet.insert(num);
        }

        int maxLen = 0;

        // Iterate through each element in nums
        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentLen = 1;
                int currentNum = num + 1;
                while (numSet.find(currentNum) != numSet.end()) {
                    currentLen++;
                    currentNum++;
                }
                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen;
    }
};
