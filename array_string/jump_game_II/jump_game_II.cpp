/* You are given a 0-indexed array of integers nums
 * of length n. You are initially positioned at nums[0].
 *
 * Each element nums[i] represents the maximum length
 * of a forward jump from index i. In other words,
 * if you are at nums[i], you can jump to any
 * nums[i+j] where:
 *
 *  0 <= j <= nums[i] and
 *  i + j < n
 *
 * Return the minimum number of jumps to reach nums[n-1].
 * The test cases are generated such that you can reach
 * nums[n-1]. */

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) {
                    dp[i] = std::min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
