class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // any array of size 1 has 1 unique element
        // therefore we start with this assumption
        // and begin our iteration on the second element
        int unique = 1;
        for (int i = 1; i < nums.size(); ++i) {
            // if unique, insert and increment unique
            if (nums[i] != nums[i-1]) {
                nums[unique] = nums[i];
                unique++;
            }
            // else, move forward
        }
        return unique;
    }
};
