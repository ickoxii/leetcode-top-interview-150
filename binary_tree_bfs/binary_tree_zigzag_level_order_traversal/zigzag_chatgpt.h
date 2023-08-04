
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        deque<TreeNode*> q;
        q.push_back(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                if (leftToRight) {
                    TreeNode* node = q.front();
                    q.pop_front();
                    currentLevel.push_back(node->val);
                    
                    if (node->left != nullptr)
                        q.push_back(node->left);

                    if (node->right != nullptr)
                        q.push_back(node->right);
                } else {
                    TreeNode* node = q.back();
                    q.pop_back();
                    currentLevel.push_back(node->val);
                    
                    if (node->right != nullptr)
                        q.push_front(node->right);

                    if (node->left != nullptr)
                        q.push_front(node->left);
                }
            }
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }
        return result;
    }
};
