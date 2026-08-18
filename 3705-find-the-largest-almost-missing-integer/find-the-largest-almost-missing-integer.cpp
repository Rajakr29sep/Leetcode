class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto& it : nums) {
            mp[it]++;
        }
        int ans = -1;
        if (k == 1) {
            for (auto& it : mp) {
                if (it.second == 1) {
                    ans = max(ans, it.first);
                }
            }
            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        } else {
            if(mp[nums[0]]==1){
                ans = max(ans,nums[0]);
            }

            if(mp[nums[n-1]]==1){
                ans = max(nums[n-1],ans);
            }
            
        }

        return ans;
    }
};