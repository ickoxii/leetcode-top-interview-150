 /**
  * Given the root of a complete binary tree, return
  * the number of the nodes in the tree.
  *
  * Design an algorithm that runs in less than O(n)
  * time complexity. */

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
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
