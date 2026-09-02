class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        queue<pair<pair<int, int>, int>> q;
        int sr, sc;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({{i, j}, 0});
                    sr = i;
                    sc = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    cnt++;
                }
            }
        }

        int target = (1 << cnt) - 1;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        int moves = 0;
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(target + 1, 0)));
        vis[sr][sc][0] = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [p, mask] = q.front();
                auto [i, j] = p;
                q.pop();
                if (mask == target) {
                    return moves;
                }
                for (int k = 0; k < 4; k++) {
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {

                        char ch = grid[nrow][ncol];

                        // 1. Wall
                        if (ch == '#')
                            continue;

                        int newMask = mask;

                        // 2. Lock
                        if (ch >= 'A' && ch <= 'F') {
                            int key = ch - 'A';

                            // key nahi hai
                            if (!(mask & (1 << key)))
                                continue;
                        }

                        // 3. Key
                        if (ch >= 'a' && ch <= 'f') {
                            newMask |= (1 << (ch - 'a'));
                        }

                        // 4. Ab visited check
                        if (!vis[nrow][ncol][newMask]) {
                            vis[nrow][ncol][newMask] = 1;
                            q.push({{nrow, ncol}, newMask});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};