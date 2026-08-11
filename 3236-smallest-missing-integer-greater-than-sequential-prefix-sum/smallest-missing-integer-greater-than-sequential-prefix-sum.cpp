class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        int n = nums.size();
        int j = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
                j = i;
            } else
                break;
        }
        cout << sum << endl;

        sort(nums.begin(), nums.end());

        auto it = lower_bound(nums.begin(), nums.end(), sum);

        if (it == nums.end() || *it != sum)
            return sum;

        int idx = it - nums.begin();
        cout << sum << idx << endl;
        for (int j = idx; j < n; j++) {
            if (sum == nums[j]) {
                while (j+1<n && nums[j + 1] == nums[j]) {
                    j++;
                }
                sum++;
            } else
                break;
        }
        return sum;
    }
};