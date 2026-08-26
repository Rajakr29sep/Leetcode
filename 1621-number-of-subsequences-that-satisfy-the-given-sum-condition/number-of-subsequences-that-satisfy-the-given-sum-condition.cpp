class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = (power(a, b / 2)) % mod;
        long long ans = (half * half) % mod;
        if (b % 2 != 0) {
            ans = (ans * a) % mod;
        }

        return ans % mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        long long ans = 0;

        while (i <= j) {

            if (nums[i] + nums[j] <= target) {
                ans = (ans + power(2, j - i)) % mod;

                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};