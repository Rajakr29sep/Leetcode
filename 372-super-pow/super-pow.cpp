class Solution {
public:
    int MOD = 1337;
    long long powExp(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = powExp(a, b / 2);

        long long ans = (half * half) % MOD;

        if (b % 2)
            ans = (ans * a) % MOD;

        return ans;
    }
    int superPow(int a, vector<int>& b) {
        if (a == 1)
            return 1;

        int n = b.size();
        long long ans = powExp(a, b[0]);

        for (int i = 1; i < n; i++) {
            ans = (powExp(ans, 10) * powExp(a, b[i])) % MOD;
        }

        return ans;
    }
};