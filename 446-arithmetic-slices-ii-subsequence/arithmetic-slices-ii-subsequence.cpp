class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 0;

        long long ans = 0;

        vector<unordered_map<long long, long long>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - 1LL * nums[j];

                if (dp[j].find(diff) != dp[j].end()) {

                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
                dp[i][diff]++;
            }
        }

        return ans;
    }
};