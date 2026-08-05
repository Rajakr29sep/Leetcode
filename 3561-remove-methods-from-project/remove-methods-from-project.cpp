class Solution {
public:
    bool toRemove(vector<vector<int>>& adj, int i, vector<int>& vis) {

        vis[i] = 1;
        for (auto& it : adj[i]) {
            if (vis[it] == -1)
                return false;
            if (vis[it] == 0) {
                if (!toRemove(adj, it, vis))
                    return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = -1;
        for (auto& it : adj[i]) {
            if (vis[it] == 0) {
                dfs(adj, it, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(adj, k, vis);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && !toRemove(adj, i, vis)) {
                flag = false;
                break;
            }
        }

        if (!flag) {
            vector<int> v(n);

            iota(v.begin(), v.end(), 0);
            return v;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] != -1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};