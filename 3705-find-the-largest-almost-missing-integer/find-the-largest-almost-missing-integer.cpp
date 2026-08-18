class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> mp2;
            for (int j = i; j < i + k; j++) {
                mp2[nums[j]] = 1;
            }

            for (auto& it : mp2) {
                mp[it.first] += it.second;
            }
        }
        int ans = -1;
        for (auto& it : mp) {
            if (it.second == 1)
                ans = max(ans, it.first);
        }

        return ans;
    }
};