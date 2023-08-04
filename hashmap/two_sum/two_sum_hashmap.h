class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        vector<int> returnIndices;
        bool found = false;

        for (int i = 0; i < nums.size() && !found; ++i) {
            if (diff.count(nums[i])) {
                unordered_map<int, int>::iterator ndx = diff.find(nums[i]);
                returnIndices.push_back(ndx->second);
                returnIndices.push_back(i);
                found = true;
            } else {
                diff[target - nums[i]] = i;
            }
        }

        return returnIndices;
    }
};
