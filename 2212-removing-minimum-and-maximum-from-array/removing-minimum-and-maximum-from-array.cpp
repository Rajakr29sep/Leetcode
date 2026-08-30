class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        if (maxIndex <= n / 2 && minIndex <= n / 2) {
            return max(maxIndex, minIndex) + 1;
        }
        if (maxIndex >= n / 2 && minIndex >= n / 2) {
            return max(n - maxIndex, n - minIndex);
        }

        return min(
            {min(maxIndex, minIndex) + 1 +
                 min(n - max(maxIndex, minIndex), abs(minIndex - maxIndex)),
             n - max(maxIndex, minIndex) +
                 min(abs(minIndex - maxIndex), min(maxIndex, minIndex) + 1)});
    }
};