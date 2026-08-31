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
    vector<vector<int>> ans;
    vector<int> arr;
    vector<vector<int>> helper(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return ans;
        }
        targetSum -= root->val;
        arr.push_back(root->val);
        if (root->right == NULL && root->left == NULL && targetSum == 0) {
            ans.push_back(arr);
        } else {
            helper(root->left, targetSum);
            helper(root->right, targetSum);
        }
        arr.pop_back();
        return ans;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};
