class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKIdx = -1;
        int maxKIdx = -1;
        int culpritIdx = -1;
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == minK) {
                minKIdx = i;
            }
            if (nums[i] == maxK) {
                maxKIdx = i;
            }
            if (nums[i] < minK || nums[i] > maxK) {
                culpritIdx = i;
            }
            int smallerIdx = min(minKIdx, maxKIdx);
            int temp = smallerIdx - culpritIdx;
            ans += (temp < 0 ? 0 : temp);
        }
        return ans;
    }
};