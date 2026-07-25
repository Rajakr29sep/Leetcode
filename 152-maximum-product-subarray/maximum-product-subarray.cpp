class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefix = 1;
        int suffix = 1;

        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - 1 - i];

            // Update the max answer with the current prefix or suffix
            ans = max({ans, prefix, suffix});
        }
     

        return ans;
    }
};