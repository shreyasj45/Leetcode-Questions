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
    vector<int> temp;
    void func(TreeNode* root){
        if(root == NULL)
            return;

        func(root->left);
        temp.push_back(root->val);
        func(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        func(root);

        int i = 0;
        int j = temp.size() - 1;

        while(i < j){
            int sum = temp[i] + temp[j];

            if(sum == k)
                return true;

            else if(sum < k)
                i++;

            else
                j--;
        }

        return false;
    }
};