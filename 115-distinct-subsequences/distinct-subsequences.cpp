class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>&dp) {

        // t completely formed
        if (j == t.length())
            return 1;

        // s exhausted but t still remains
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int notPick = solve(i + 1, j, s, t,dp);
        int pick = 0;

        if (s[i] == t[j]) {
            pick = solve(i + 1, j + 1, s, t,dp);
        }

        return dp[i][j] = pick + notPick;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0, s, t,dp);
    }
};