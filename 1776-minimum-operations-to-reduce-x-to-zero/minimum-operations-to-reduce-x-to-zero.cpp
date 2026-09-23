class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        long long target = accumulate(nums.begin(), nums.end(), 0LL) - x;
        if (target == 0)
            return nums.size();
        unordered_map<int, int> mp;
        long long sum = 0;
        int ans = -1;
        mp[0] = -1;
        int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == target) {
                ans = max(i - j + 1, ans);
            } else if (mp.find(sum - target) != mp.end()) {
                ans = max(ans, i - mp[sum - target]);
            }
            mp[sum] = i;
        }

        if (ans == -1)
            return -1;
        return n - ans;
    }
};