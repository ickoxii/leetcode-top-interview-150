 /**
  * Given the root of a binary tree, return the zigzag
  * level order traversal of its nodes' values. (i.e.,
  * from left to right, then right to left for the
  * next level and alternate between). */

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        bool goRight = false;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            if (goRight) {
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    currentLevel.push_back(node->val);

                    if (node->left != nullptr)
                        q.push(node->left);

                    if (node->right != nullptr)
                        q.push(node->right);
                }
            }
            else {
                stack<TreeNode*> reverse;
                while (!q.empty()) {
                    TreeNode *node = q.front();
                    q.pop();
                    reverse.push(node);
                }
                while (!reverse.empty()) {
                    TreeNode *node = reverse.top();
                    reverse.pop();
                    currentLevel.push_back(node->val);

                    if (node->right != nullptr)
                        q.push(node->right);

                    if (node->left != nullptr)
                        q.push(node->left);
                }
            }

            result.push_back(currentLevel);

            goRight = (goRight) ? false : true;
        }

        return result;
    }
};
