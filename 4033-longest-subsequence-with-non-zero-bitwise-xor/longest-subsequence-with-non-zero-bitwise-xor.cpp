class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int nonZero = 0;
        int ans = 0;
        int n =nums.size();
        for (int i = 0; i < n; i++) {
            ans ^= nums[i];
            if (nums[i] != 0) {
                nonZero = 1;
            }
        }
        if (ans != 0)
            return n;
        if (ans == 0 && nonZero == 0)
            return 0;

        return n - 1;
    }
};