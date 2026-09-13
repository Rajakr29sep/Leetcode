class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int k = 1; k <= n; k++) {
            int ans = INT_MAX;

            for (int i = 1; i * (i + 1) / 2 <= k; i++) {
                int points = i * (i + 1) / 2;

                ans = min(ans, i + 1 + dp[k - points]);
            }
            dp[k] = ans;
        }
        return dp[n] - 1;
    }
};