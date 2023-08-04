 /**
  * Given the root of a binary tree, return the average
  * value of the nodes on each level in the form of an
  * array. Answers within 10^-5 of the actual answer
  * will be accepted. */

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        if (root == nullptr) return averages;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            long sum = 0;
            int count = 0;
            queue<TreeNode*> temp;

            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                count++;

                if (node->left != nullptr)
                    temp.push(node->left);

                if (node->right != nullptr)
                    temp.push(node->right);
            }

            q = temp;
            averages.push_back(static_cast<double>(sum) / count);
        }

        return averages;
    }
};
