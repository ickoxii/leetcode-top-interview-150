/* Given an integer array nums, return an array answer
 * such that answer[i] is equal to the product of all
 * the elements of nums except nums[i];
 *
 * The product of any prefix or suffix of nums is
 * guaranteed to fit in a 32-bit integer.
 *
 * You must write an algorithm that runs in O(n) time
 * and without using the division operation. */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int prefix = 1; // stores the prefix product

        // calculate prefix products
        // keeps a product of all elements to the left
        for (int i = 0; i < nums.size(); ++i) {
            answer[i] = prefix;
            prefix = prefix * nums[i];
        }

        int suffix = 1; // stores the suffix product

        // update answers with suffix product
        // keeps a product of all elements to the right
        for (int i = nums.size() - 1; i >= 0; --i) {
            answer[i] = answer[i] * suffix;
            suffix = suffix * nums[i];
        }

        return answer;
    }
};

/* too slow, works in O(n^2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) {
                    product *= nums[j];
                }
            }
            answer.push_back(product);
        }

        return answer;
    }
};
*/
