class Solution {
public:
    int n;
    int dp[50005][2];

    int solve(vector<int>& stoneValue, int i, int turn) {
        if (i >= n)
            return 0;

        if (dp[i][turn] != -1)
            return dp[i][turn];

        if (turn) { // Alice
            int ans = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                ans = max(ans, sum + solve(stoneValue, i + k + 1, 0));
            }

            return dp[i][turn] = ans;
        } else { // Bob
            int ans = INT_MAX;

            for (int k = 0; k < 3 && i + k < n; k++) {
                ans = min(ans, solve(stoneValue, i + k + 1, 1));
            }

            return dp[i][turn] = ans;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        memset(dp, -1, sizeof(dp));

        int alice = solve(stoneValue, 0, 1);

        int total = 0;
        for (int x : stoneValue)
            total += x;

        int bob = total - alice;

        if (alice > bob)
            return "Alice";
        if (bob > alice)
            return "Bob";
        return "Tie";
    }
};