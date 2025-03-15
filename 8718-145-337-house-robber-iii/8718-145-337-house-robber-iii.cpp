class Solution {
public:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;
    
    int solve(TreeNode* root, bool can) {
        if (!root) return 0;
        if (dp[root].count(can)) return dp[root][can];
        int result = 0;
        if (can) {
            int take = root->val + solve(root->left, false) + solve(root->right, false);
            int leave = solve(root->left, true) + solve(root->right, true);
            result = max(take, leave);
        } 
        else 
            result = solve(root->left, true) + solve(root->right, true);
        return dp[root][can] = result;
    }
    
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};