class Solution {
public:
    typedef long long ll;
    bool solve(ll mid, vector<int>& coins, int k) {
        ll correctedCount = 0;
        int n = coins.size();

        // 2^n * n * log(maxCoin)
        for (int expressions = 1; expressions <= (1 << n) - 1;
             expressions++) { // 2^n-1 expressions
            ll lcm = 0;
            ll order = 0; // even or odd order of expressions

            for (int i = 0; i < n; i++) {
                if (expressions & (1 << i)) {
                    order++; // we have taken ith coin

                    if (lcm == 0) {
                        lcm = coins[i];
                    } else {
                        lcm = lcm * coins[i] / gcd(lcm, coins[i]);
                    }
                }
            }

            if (order % 2 == 0) { // even then subtract
                correctedCount -= mid / lcm;
            } else {
                correctedCount += mid / lcm;
            }
        }

        return correctedCount >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long s = *min_element(coins.begin(), coins.end());
        long long e = (ll)(*max_element(begin(coins), end(coins))) * k;

        long long ans = 0;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            if (solve(mid, coins, k)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
