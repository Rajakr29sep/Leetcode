class Solution {
public:
    bool solve(int n, int turn, vector<vector<int>>& dp) {
        if (n <= 0) {
            return turn == 0;
        }
        if (dp[n][turn] != -1)
            return dp[n][turn];

        bool ans = false;
        if (!turn)
            ans = true;
        int k = n;
        for (int k = 1; k * k <= n; k++) {
               int square = k * k;
            if (turn) {
                ans = ans || solve(n - square, !turn, dp);
                if (ans)
                    break;
            } else {
                ans = ans && solve(n-square, !turn, dp);
                if (!ans)
                    break;
            }
        }

        return dp[n][turn] = ans;
    }

    bool winnerSquareGame(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(n, 1, dp);
    }
};