class Solution {
public:
    int t[2][101][101];
    int solve(int turn, vector<int>& piles, vector<int>& prefix, int i, int M) {
        if (i >= piles.size())
            return 0;
        if(t[turn][i][M]!=-1)return t[turn][i][M];
        int ans;
        if (turn)
            ans = 0;
        else
            ans = INT_MAX;
        for (int k = i; k < min((int)piles.size(), i + 2 * M); k++) {
            int taken = k - i + 1;
            if (turn) {
                ans = max(ans, prefix[k] - (i > 0 ? prefix[i - 1] : 0) +
                                     solve(!turn, piles, prefix, k + 1,
                                           max(M, taken)));
            } else {
                ans = min(ans,
                           solve(!turn, piles, prefix, k + 1, max(M, taken)));
            }
        }
        return t[turn][i][M]= ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        int n = piles.size();
        vector<int> prefix(n);
        prefix[0] = piles[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + piles[i];
        }
        return solve(1, piles, prefix, 0, 1);
    }
};