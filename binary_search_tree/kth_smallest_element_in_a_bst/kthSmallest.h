 /**
  * Given the root of a binary search tree, and an integer k,
  * return the kth smallest value (1-indexed) of all the
  * values of the nodes in the tree */

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
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        stack<TreeNode *> nodes;
        TreeNode *iter = root;

        while(iter || !nodes.empty()) {
            while (iter) {
                nodes.push(iter);
                iter = iter->left;
            }

            iter = nodes.top();
            nodes.pop();
            i += 1;

            if (i == k)
                return iter->val;

            iter = iter->right;
        }
    }

    return -1; // this line should never be reached
};
