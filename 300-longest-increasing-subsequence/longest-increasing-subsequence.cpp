// amazon,samsung,zoho
class Solution {
    // int solve(int i, vector<int>& nums, int m, int prev,
    //           vector<vector<int>>& dp) {
    //     if (i >= m)
    //         return 0;
    //     if (dp[i][prev + 1] != -1)
    //         return dp[i][prev + 1];
    //     int notPick = solve(i + 1, nums, m, prev, dp);
    //     int pick = 0;
    //     if (prev == -1 || nums[prev] < nums[i]) {
    //         pick = 1 + (solve(i + 1, nums, m, i, dp));
    //     }

    //     return dp[i][prev + 1] = max(pick, notPick);
    // }

public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        /*********                tabulation*              ********************/
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        // return solve(0, nums, m, -1, dp);
        for (int i = m-1; i>=0; i--) {
            for (int prev =i; prev >=0; prev--) {
                int notPick = dp[i+1][prev];
                int pick = 0;
                if (prev == 0 || nums[prev-1] < nums[i]) {
                    pick = 1 + dp[i+1][i+1];
                }
                dp[i][prev] = max(pick, notPick);
            }
        }
        return dp[0][0];
        /************************************m-2****************/
        // vector<int> t(m, 1);
        // int maxi = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[j] < nums[i])
        //             t[i] = max(t[j] + 1, t[i]);
        //     }
        //     maxi = max(maxi, t[i]);
        // }
        // return maxi;
        /*************************using binary search**********************/
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for (int i = 1; i < m; i++) {
        //     if (nums[i] > temp.back()) {
        //         temp.push_back(nums[i]);
        //     } else {
        //         auto idx = lower_bound(temp.begin(), temp.end(),nums[i]);
        //         temp[idx- temp.begin()] = nums[i];
        //     }
        // }
        // return temp.size();
    }
};