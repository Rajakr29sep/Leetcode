class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;
        k = k % size;

        int i = k / n;
        int j = k % n;

        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        int idx = 0;

        while (ans[i][j] == INT_MAX) {
            ans[i][j] = grid[idx / n][idx % n];
            idx = (idx + 1) % size;
            if(j == n-1)
            i = (i + 1) % m;
            j = (j + 1) % n;
        }

        return ans;
    }
};