/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int idx = 0;
    TreeNode* helper(vector<int>& preorder, int val) {
        if (idx == preorder.size() || val < preorder[idx]) {
            return NULL;
        }
        TreeNode* curr = new TreeNode(preorder[idx]);
        idx++;

        curr->left = helper(preorder, curr->val);
        curr->right = helper(preorder, val);

        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, INT_MAX);
    }
};