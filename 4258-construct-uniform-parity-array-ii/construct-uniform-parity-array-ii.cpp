class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0;
        int even = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                even++;
            } else
                odd++;

            mini = min(mini, nums1[i]);
        }

        if (odd == 0 || even == 0 || mini % 2 == 1 )
            return true;

        return false;
    }
};