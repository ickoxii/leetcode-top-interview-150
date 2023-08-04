 /**
  * Given a binary tree, find the lowest common ancestor (LCA)
  * of two given nodes in the tree.
  *
  * According to the definition of LCA on Wikipedia: "The LCA
  * is defined between two nodes p and q as the lowest node
  * in T that has both p and q as descendants (where we allow
  * a node to be a descendant of itself)." */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL; // if root is NULL
        if (root == p || root == q) return root; // if root is p or q

        // Recursive calls for left and right subtrees
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // If both p and q exist in Tree rooted at root
        // then return root (This is the LCA node).
        // check if left and right are not null
        if (left && right) return root;

        // If left is NULL, that means p and q are in the
        // right subtree, return right
        // Else if right is NULL, that means p and q are in
        // the left subtree, return left
        // if both left and right are NULL, return NULL
        return left ? left : right;
    }
};
