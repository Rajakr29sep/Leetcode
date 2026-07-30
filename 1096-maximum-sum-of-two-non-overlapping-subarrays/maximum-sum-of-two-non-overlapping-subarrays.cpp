class Solution {
public:
    int solve(vector<int>& prefixSum, int len1, int len2, int s, int e) {
        int n = prefixSum.size();
        int maxi = INT_MIN;
        for (int i = 0; i <= n - len2; i++) {
            if (i + len2 - 1 < s || i > e) {
                int sum1 = (prefixSum[i + len2 - 1] -
                            (i - 1 >= 0 ? prefixSum[i - 1] : 0));
                maxi = max(sum1, maxi);
            }
        }
        return maxi;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        int maxi = INT_MIN;
        for (int i = 0; i <= n - firstLen; i++) {
            int sum1 = (prefixSum[i + firstLen - 1] -
                        (i - 1 >= 0 ? prefixSum[i - 1] : 0));
            maxi = max(sum1 + solve(prefixSum, firstLen, secondLen, i,
                                    i + firstLen - 1),
                       maxi);
        }
        return maxi;
    }
};