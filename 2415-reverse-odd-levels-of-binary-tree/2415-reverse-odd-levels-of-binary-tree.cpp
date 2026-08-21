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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> ans;
            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                q.pop();
                ans.push_back(top);
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
            if (level % 2 == 1) {
                int i = 0, j = ans.size() - 1;
                while (i <= j) {
                    swap(ans[i]->val, ans[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};