class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = 0;
        int secondMax = 0;
        int n=  nums.size();
        for (int i = 0; i < n; i++) {
            if (firstMax <= nums[i]) {
                secondMax = firstMax;
                firstMax = nums[i];
            } else if (secondMax < nums[i]) {
                secondMax = nums[i];
            }
        }

        return ((firstMax - 1) * (secondMax - 1));
    }
};