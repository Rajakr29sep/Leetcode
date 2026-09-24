class Solution {
public:
    bool solve(int i, int digit) {
        int sum = 0;
        while (digit) {
            sum += ((digit % 10));
            digit /= 10;
        }
        return sum == i;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (solve(i, nums[i])) {
                return i;
            }
        }

        return -1;
    }
};