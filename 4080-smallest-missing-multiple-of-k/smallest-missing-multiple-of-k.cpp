class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int prev = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            if ((nums[i] % k) == 0) {
                if (prev != (nums[i] - k)) {
                    return prev + k;
                }
                prev = nums[i];
            }
        }

        return prev + k;
    }
};