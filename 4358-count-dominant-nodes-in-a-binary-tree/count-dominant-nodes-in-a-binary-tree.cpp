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
 pair<int, int> solve(TreeNode* root) {
        if (!root) return {INT_MIN, 0};
        auto left = solve(root->left);
        auto right = solve(root->right);

        int mx = max(root->val, max(left.first, right.first));
        int cnt = left.second+right.second + (root->val == mx);
        return {mx, cnt};
    }
    int countDominantNodes(TreeNode* root) {
        TreeNode* norlavetic = root;
        return solve(norlavetic).second;
    }
};