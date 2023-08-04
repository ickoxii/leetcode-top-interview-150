 /**
  * You are given the root of a binary tree containing
  * the digits from 0 to 9 only.
  *
  * Each root-to-leaf path in the tree represents a
  * number.
  *     
  *     ex: 1
  *        / \
  *       2   3
  *
  *     the root-to-leaf path to the values 1->2
  *     represents the number 12.
  *     the root-to-leaf path to the values 1->3
  *     represents the number 13
  *     sum = 12+13 = 23
  *
  * Return the total sum of all root-to-leaf numbers. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sumHelper(TreeNode *node, int currentSum) {
        if (!node)
            return 0;

        currentSum = currentSum * 10 + node->val;

        if (!node->left && !node->right)
            return currentSum;

        int leftSum = sumHelper(node->left, currentSum);
        int rightSum = sumHelper(node->right, currentSum);

        return leftSum + rightSum;
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumHelper(root, 0);
    }
};
