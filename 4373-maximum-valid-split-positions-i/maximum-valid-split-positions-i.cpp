class Solution {
public:

    int solve(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1)
            return 0;

        vector<int> gcdL(n);
        vector<int> gcdR(n);

        // Prefix GCD
        gcdL[0] = arr[0];

        for (int i = 1; i < n; i++) {
            gcdL[i] = gcd(gcdL[i - 1], arr[i]);
        }

        // Suffix GCD
        gcdR[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            gcdR[i] = gcd(gcdR[i + 1], arr[i]);
        }

        int ans = 0;

        // Split between i-1 and i
        for (int i = 1; i < n; i++) {
            if (gcdL[i - 1] == gcdR[i]) {
                ans++;
            }
        }

        return ans;
    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

        // At most one deletion.
        // del = -1 means don't delete anything.
        int ans = solve(nums);

        for (int del = 0; del < n; del++) {

            vector<int> arr;

            for (int i = 0; i < n; i++) {
                if (i != del) {
                    arr.push_back(nums[i]);
                }
            }

            ans = max(ans, solve(arr));
        }

        return ans;
    }
};