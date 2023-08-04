/* Given an integer array nums, return all the triplets
 * [nums[i], nums[j], nums[k]] such that i != j, i != k,
 * and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate
 * triplets. */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums;
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); // Sort the array to skip duplicate elements

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> threeSums;
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); // Sort the array to skip duplicate elements

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 1; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int complement = -(nums[i] + nums[j]);
                if (binary_search(nums.begin() + j + 1, nums.end(), complement)) {
                    vector<int> triplet = {nums[i], nums[j], complement};
                    threeSums.push_back(triplet);
                }
            }
        }

        return threeSums;
    }
};

                continue;

            for (int j = i + 1; j < n - 1; ++j) {
                // skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int complement = -(nums[i] + nums[j]);
                if (binary_search(nums.begin() + j + 1, nums.end(), complement)) {
                    vector<int> triplet = {nums[i], nums[j], complement};
                    threeSums.push_back(triplet);
                }
            }
        }

        return threeSums;
    }
};

