class Solution {
public:
    vector<int> dp;
    int solve(int n) {
        if (n == 0)
            return 1;
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, i * solve(n - i));
        }
        return dp[n] = ans;
    }
    int integerBreak(int n) {

        dp.resize(n + 1, -1);

        int ans = INT_MIN;

        for (int i = 1; i < n; i++) {
            ans = max(ans, i * solve(n - i));
        }

        return ans;
    }
};