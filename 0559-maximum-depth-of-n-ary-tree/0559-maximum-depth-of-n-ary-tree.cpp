/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int depth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int mx = 0;
        for (auto node : root->children) {
            mx = max(mx, depth(node));
        }
        return mx+1;
    }
    int maxDepth(Node* root) { 
        return depth(root);
    }
};