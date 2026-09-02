class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        queue<pair<pair<int, int>, pair<int, int>>> q;

        int m = classroom.size();
        int n = classroom[0].size();

        int total = 0;
        int sr, sc;
        vector<vector<int>> count(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    q.push({{i, j}, {energy, 0}});
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    count[i][j] = total++;
                }
            }
        }
        int target = (1 << total) - 1;
        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << total, false))));
        vis[sr][sc][energy][0] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [p, qr] = q.front();

                auto [i, j] = p;
                auto [e, mask] = qr;
                q.pop();

                if (mask == target)
                    return moves;
                if (e == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    // Out of bounds
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                        continue;

                    // Obstacle
                    if (classroom[ni][nj] == 'X')
                        continue;

                    // Moving costs 1 energy
                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Recharge
                    if (classroom[ni][nj] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter
                    if (classroom[ni][nj] == 'L') {
                        newMask |= (1 << count[ni][nj]);
                    }

                    // Visit new STATE
                    if (!vis[ni][nj][newEnergy][newMask]) {

                        vis[ni][nj][newEnergy][newMask] = true;

                        q.push({{ni, nj}, {newEnergy, newMask}});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};