class Solution {
public:
    int dp[105][105][205];

    bool solve(int i, int j, int m, int n, vector<vector<char>>& grid,
               int balance) {

        if (i >= m || j >= n || balance < 0)
            return false;

        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool right = solve(i, j + 1, m, n, grid, balance);
        bool down = solve(i + 1, j, m, n, grid, balance);

        return dp[i][j][balance] = (right || down);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, m, n, grid, 0);
    }
};