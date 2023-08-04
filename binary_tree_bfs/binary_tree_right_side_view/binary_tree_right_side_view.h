 /**
  * Given the root of a binary tree, imagine yourself
  * standing on the right side of it, return the values
  * of the nodes you can see ordered from top to bottom. */

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

// uses a level order traversal to determine the right-most
// node in each level.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> rightSide;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();

                // only record the rightmost node in each level
                if (i == size - 1)
                    rightSide.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
            }
        }

        return rightSide;
    }
};
