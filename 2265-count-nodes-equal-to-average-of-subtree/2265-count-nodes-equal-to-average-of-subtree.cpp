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
    int ans=0;
    int sum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);
        return left + right + root->val;
    }

    int count(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lc = count(root->left);
        int rc = count(root->right);
        return 1 + lc + rc;
    }

    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        int s = sum(root);
        int c = count(root);

        if(s/c == root->val){
            ans++;
        }
        helper(root->left);
        helper(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
};