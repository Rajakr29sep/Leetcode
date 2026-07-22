class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];
        int i = 0;
        int j = 0;
        int k = n - 1;
        while (j <= k) {

            int idx = (1 + 2 * j) % (n | 1);
            if (nums[ idx] > median) {
                swap(nums[(1 + 2 * i) % (n | 1)], nums[(1 + 2 * j) % (n | 1)]);
                i++;
                j++;
            } else if (nums[idx] == median) {
                j++;
            } else if (nums[idx] < median) {
                swap(nums[(1 + 2 * j) % (n | 1)], nums[(1 + 2 * k) % (n | 1)]);
                k--;
            }
        }
    }
};