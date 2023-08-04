class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ndx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[ndx] = nums[i];
                ndx++;
            }
        }
        return ndx;
    }
};
