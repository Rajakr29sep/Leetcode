class Solution {
public:
    int solve(int i, int j, vector<int>& prefix, vector<vector<int>>&dp) {
        if (i >= j || i < 0 || j >= prefix.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int sum = 0;

        for (int k = i + 1; k <= j; k++) {
            int leftSum = prefix[k - 1] - (i > 0 ? prefix[i - 1] : 0);
            int rightSum = prefix[j] - (k - 1 >= 0 ? prefix[k - 1] : 0);
            if (leftSum < rightSum) {
                sum = max(sum, leftSum + solve(i, k - 1, prefix,dp));
            } else if (leftSum > rightSum) {
                sum = max(sum, rightSum + solve(k, j, prefix,dp));
            } else {
                sum = max(sum, leftSum + solve(i, k - 1, prefix,dp));
                sum = max(sum, rightSum + solve(k, j, prefix,dp));
            }
        }
        return dp[i][j] = sum;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }

        return solve(0, n - 1, prefix, dp);
    }
};