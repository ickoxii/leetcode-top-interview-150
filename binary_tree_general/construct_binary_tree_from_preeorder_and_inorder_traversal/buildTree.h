/* Given two integer arrays preorder and inorder where
 * preorder is the preorder traversal of a binary tree
 * and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree. */

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

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    TreeNode* buildTreeHelper(const vector<int>& preorder, const vector<int>& inorder,
                              unordered_map<int, int>& inMap, int istart, int iend, int& pndx) {
        if (pndx >= preorder.size() || istart > iend)
            return nullptr;
        
        int indx = inMap[preorder[pndx]];
        TreeNode* node = new TreeNode(preorder[pndx]);

        pndx = pndx + 1;
        node->left = buildTreeHelper(preorder, inorder, inMap, istart, indx - 1, pndx);
        node->right = buildTreeHelper(preorder, inorder, inMap, indx + 1, iend, pndx);

        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap; // maps values to indices
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()) 
            return nullptr;

        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;

        int pndx = 0;
        return buildTreeHelper(preorder, inorder, inMap, 0, preorder.size() - 1, pndx);
    }
};
