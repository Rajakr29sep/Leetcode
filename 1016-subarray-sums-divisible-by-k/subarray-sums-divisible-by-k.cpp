class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = ((sum % k) + k) % k;
            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};