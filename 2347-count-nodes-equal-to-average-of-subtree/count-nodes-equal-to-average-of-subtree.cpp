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
    int ans = 0;
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        int sum = 0;
        auto [sum1, cnt1] = solve(root->left);
        auto [sum2, cnt2] = solve(root->right);
        sum = sum1 + sum2 + root->val;
        int cnt = cnt1 + cnt2 + 1;
        int average = (sum) / (cnt);
        if (root->val == average) {
            ans++;
        }
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};