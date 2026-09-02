class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();
        vector<vector<int>> adj(m + 1);
        int target = (1 << m) - 1;
        vector<vector<int>> vis(m, vector<int>(target + 1, 0));
        for (int i = 0; i < m; i++) {

            for (int neighbour : graph[i]) {
                adj[i].push_back(neighbour);
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            int mask = 1 << i;

            q.push({i, mask});
            vis[i][mask] = true;
        }

        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, mask] = q.front();
                if (mask == target)
                    return moves;
                q.pop();

                for (auto& it : adj[node]) {
                    int newMask = mask | (1 << it);

                    if (!vis[it][newMask]) {
                        vis[it][newMask] = true;
                        q.push({it, newMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};