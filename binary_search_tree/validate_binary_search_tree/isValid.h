 /**
  * Given the root of a binary tree, determine if it
  * is a valid BST.
  *
  * a valid BST is defined as follows:
  *
  * the left subtree of a node contains only nodes
  * with keys less than the node's key.
  *
  * the right subtree of a node contains only nodes
  * with keys greater than the node's key.
  *
  * both the left and right subtrees must also be
  * binary search trees. */

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
private:
    bool isValidHelper(TreeNode *node, long long lower, long long upper) {
        if (node == nullptr)
            return true;

        if (node->val <= lower || node->val >= upper)
            return false;

        return isValidHelper(node->left, lower, node->val) &&
               isValidHelper(node->right, node->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }
};
