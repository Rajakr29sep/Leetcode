class Solution {
public:
    int solve(vector<int>& prefixSum, int len1, int len2, int i, int count,
              vector<vector<int>>& dp) {

        if (i >= prefixSum.size() || count >= 2) {
            return 0;
        }
        if (dp[i][count] != -1)
            return dp[i][count];
        int n = prefixSum.size();
        int maxi = 0;
        if (count == 0) {
            if (i + len1 - 1 < prefixSum.size()) {
                maxi = max(
                    prefixSum[i + len1 - 1] - (i > 0 ? prefixSum[i - 1] : 0) +
                        solve(prefixSum, len1, len2, i + len1, count + 1, dp),
                    solve(prefixSum, len1, len2, i + 1, count, dp));
            } else {
                maxi = solve(prefixSum, len1, len2, i + 1, count, dp);
            }

        } else if (count == 1) {
            if (i + len2 <= prefixSum.size()) {
                maxi = max(
                    prefixSum[i + len2 - 1] - (i > 0 ? prefixSum[i - 1] : 0) +
                        solve(prefixSum, len1, len2, i + len2, count + 1, dp),
                    solve(prefixSum, len1, len2, i + 1, count, dp));
            } else {
                maxi = solve(prefixSum, len1, len2, i + 1, count, dp);
            }
        }

        return dp[i][count] = maxi;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        vector<vector<int>> dp1(n + 1, vector<int>(2, -1));
        vector<vector<int>> dp2(n + 1, vector<int>(2, -1));
        return max(solve(prefixSum, firstLen, secondLen, 0, 0, dp1),
                   solve(prefixSum, secondLen, firstLen, 0, 0, dp2));
    }
};