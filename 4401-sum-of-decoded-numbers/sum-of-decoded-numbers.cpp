class Solution {
public:
    int MOD = 1e9 + 7;
    int powExp(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = powExp(a, b / 2);
        long long ans = (half * half) % MOD;
        if (b % 2 == 1) {
            ans = (ans * a) % MOD;
        }

        return ans % MOD;
    }

    long long solve(long long num, long long width) {

        long long xi = 0;
        long long yi = 0;
        string temp = to_string(num);
        for (int i = 0; i < width; i++) {
            xi = xi * 10 + (temp[i] - '0');
        }
        for (int i = width; i < temp.length(); i++) {
            yi = yi * 10 + (temp[i] - '0');
        }

        return powExp(xi, yi);
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long ans = solve(1LL * (nums[i] / 10), 1LL * (nums[i] % 10));
            sum = (sum + ans) % MOD;
        }

        return sum;
    }
};