class Solution {
public:
    int solve(vector<vector<int>>& pairs, int i, int prev,vector<vector<int>>&dp) {
        if (i >= pairs.size())
            return 0;
        if ( dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int pick = -1;

        if (prev == -1 || (pairs[prev][1] < pairs[i][0])) {
            pick = 1 + solve(pairs, i + 1, i,dp);
        }
        int notPick = solve(pairs, i + 1, prev,dp);
        return dp[i][prev+1] = max(pick, notPick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(pairs, 0, -1,dp);
    }
};