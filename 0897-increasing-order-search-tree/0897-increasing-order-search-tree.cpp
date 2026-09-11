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
    TreeNode* nextRight = NULL;
    TreeNode* ans = NULL;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        increasingBST(root->left);
        root->left = NULL;
        if(nextRight != NULL){
            nextRight->right = root;
        }
        else{
            ans = root;
        }
        nextRight = root;
        increasingBST(root->right);
        return ans;
    }
};