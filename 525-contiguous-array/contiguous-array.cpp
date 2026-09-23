class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int target = 0;
        mp[0] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if (mp.find(sum - target) != mp.end()) {
                ans = max(ans, i - mp[sum - target]);
            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};