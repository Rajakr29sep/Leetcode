class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (firstMin >= nums[i]) {
                secondMin = firstMin;
                firstMin = nums[i];
            } else if (secondMin > nums[i]) {
                secondMin = nums[i];
            }

            if (firstMax <= nums[i]) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (secondMax <= nums[i]) {
                thirdMax = secondMax;
                secondMax = nums[i];
            } else if (thirdMax < nums[i]) {
                thirdMax = nums[i];
            }
        }
        return max(1LL * firstMax * secondMax * thirdMax,
                   1LL * firstMin * secondMin * firstMax);
    }
};