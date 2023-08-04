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
private:
    /**
     * buildTreeHelper
     *
     * This function recursively builds a tree from its inorder
     * and postorder traversals. The postorder vector is read
     * in reverse from right to left, giving us the node
     * traversal order equivalent to a reversed traditional
     * preorder traversal. By reading the postorder traversal
     * backwards, we build nodes in the sequence node, right,
     * left.
     *
     * parameters:
     * inorder - inorder traversal of the tree
     * postorder - postorder traversal of the tree
     * inMap - values of inorder mapped to their indices
     * istart - beginning of range in inorder array
     * iend - end of range in inorder array
     * pndx - index of the current value of in the post
     *        order array we are adding to the tree
     *
     * return:
     * node - returns the current node created
     *
     * recursive information:
     * base case:
     *   -iend < istart - done with this part of inMap
     *      return nullptr
     * base case 2:
     *   -element position in inorder is out of the current
     *   bounds istart and iend
     *      return nullptr
     * recursive case:
     *   -build node with the current element
     *   -increment pndx and call buildTreeHelper on
     *    the right child, the left child of node
     *      return node
    */
    // call inMap by reference but not by const ref
    // because its faster than making copies but having
    // it as const fucks up some of the operators
    TreeNode *buildTreeHelper(const vector<int>& inorder, 
                              const vector<int>& postorder,
                              unordered_map<int, int>& inMap,
                              int istart, int iend, int& pndx) {
        if(pndx < 0 || iend < istart)
            return nullptr;
        
        int indx = inMap[postorder[pndx]];
        TreeNode *node = new TreeNode(inorder[indx]);

        pndx = pndx - 1;
        node->right = buildTreeHelper(inorder,
                                      postorder,
                                      inMap,
                                      indx+1,
                                      iend,
                                      pndx);
        node->left = buildTreeHelper(inorder,
                                     postorder,
                                     inMap,
                                     istart,
                                     indx-1,
                                     pndx);
 
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return nullptr;
        
        TreeNode *root = nullptr;
        unordered_map<int, int> inMap;

        // map values
        for (int i = 0; i < inorder.size(); ++i)
            inMap[inorder[i]] = i;

        // read postorder in reverse. root node is last element
        int pndx = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, inMap, 0, postorder.size() - 1, pndx);
    }
};
