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
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left,
                    int right, int& postIdx) {
        if (right < left) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = search(inorder, left, right, postorder[postIdx]);
        postIdx--;

        root->right = build(inorder, postorder, inIdx + 1, right, postIdx);
        root->left = build(inorder, postorder, left, inIdx - 1, postIdx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = inorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIdx);
    }
};