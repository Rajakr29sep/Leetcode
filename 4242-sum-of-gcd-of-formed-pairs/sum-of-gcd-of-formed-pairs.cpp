class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        long long maxi = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, 1LL*nums[i]);
            prefixGcd[i] = __gcd(1LL*nums[i], maxi);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int s = 0;
        int e = n - 1;

        while (s < e) {
            ans += __gcd(prefixGcd[s], prefixGcd[e]);
            s++;
            e--;
        }

        return ans;
    }
};