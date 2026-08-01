class Solution {
public:
    bool solve(vector<int>& monsters, vector<long long>& mp,
               long long strength) {

        int n = monsters.size();

        for (int i = 0; i < n; i++) {

            if (strength + mp[i] < monsters[i])
                return false;

            strength -= monsters[i];

            if (strength < 0)
                strength = 0;
        }

        return true;
    }

    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {

        int n = monsters.size();
        vector<long long> mp(n, 0);
        for (auto& b : boosts) {
            mp[b[0]] += b[2];
            if (b[1] + 1 < n)
                mp[b[1] + 1] -= b[2];
        }
        for (int i = 1; i < n; i++) {
            mp[i] += mp[i - 1];
        }

        long long low = 0, high = 1e18;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (solve(monsters, mp, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};