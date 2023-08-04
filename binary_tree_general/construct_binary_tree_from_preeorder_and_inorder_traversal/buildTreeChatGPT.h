#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode *buildTreeHelper(const std::vector<int> &preorder, 
                              int preStart, // start of section in preorder
                              int preEnd,   // end of section in preorder
                              const std::vector<int> &inorder, 
                              int inStart, // start of section in inorder
                              int inEnd,   // end of section in inorder
                              std::unordered_map<int, int> &inorderMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootValue = preorder[preStart];
        TreeNode *root = new TreeNode(rootValue);

        int inRootPos = inorderMap[rootValue];
        int leftSubtreeSize = inRootPos - inStart;

        root->left = buildTreeHelper(preorder, 
                                     preStart + 1, 
                                     preStart + leftSubtreeSize,
                                     inorder, 
                                     inStart, 
                                     inRootPos - 1, 
                                     inorderMap);
        root->right = buildTreeHelper(preorder, 
                                      preStart + leftSubtreeSize + 1, 
                                      preEnd,
                                      inorder, 
                                      inRootPos + 1, 
                                      inEnd, 
                                      inorderMap);

        return root;
    }

public:
    TreeNode *buildTree(std::vector<int> &preorder, 
                        std::vector<int> &inorder) {
        std::unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i)
            inorderMap[inorder[i]] = i;

        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }
};

// Helper function to print the binary tree (in-order traversal)
void printTreeInOrder(TreeNode *root) {
    if (root == nullptr)
        return;

    printTreeInOrder(root->left);
    std::cout << root->val << " ";
    printTreeInOrder(root->right);
}

int main() {
    Solution solution;

    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(preorder, inorder);

    std::cout << "In-order Traversal of the Constructed Tree: ";
    printTreeInOrder(root);
    std::cout << std::endl;

    return 0;
}
