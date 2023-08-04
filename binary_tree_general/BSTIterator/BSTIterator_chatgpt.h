
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    stack<TreeNode*> nodeStack;

    void pushAllLeft(TreeNode* node) {
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* topNode = nodeStack.top();
        nodeStack.pop();

        if (topNode->right != nullptr) {
            pushAllLeft(topNode->right);
        }

        return topNode->val;
    }

    bool hasNext() {
        return !nodeStack.empty();
    }
};
