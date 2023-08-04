 /**
  * Given the root of a Binary Search Tree (BST),
  * return the minimum absolute difference between
  * the values of any two different nodes in the tree. */

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
    int getMinimumDifference(TreeNode* root) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        queue<TreeNode *> q;

        vector<int> values;

        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                values.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }

        sort(values.begin(), values.end());

        int diff = INT_MAX;

        for (int i = 0; i < values.size() - 1; ++i) {
            if (values[i+1] - values[i] < diff)
                diff = values[i + 1] - values[i];
        }

        return diff;
    }
};
