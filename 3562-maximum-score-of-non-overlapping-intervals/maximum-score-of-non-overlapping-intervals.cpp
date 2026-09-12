class Solution {
public:
    vector<vector<long long>> dp;
    vector<vector<vector<int>>> path;

    long long solve(vector<vector<long long>>& arr, int i, int count,
                    vector<vector<int>>& intervals) {

        if (i >= arr.size() || count == 4) {
            return 0;
        }

        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        auto j =
            upper_bound(arr.begin(), arr.end(), arr[i][1],
                        [](long long value, const vector<long long>& interval) {
                            return value < interval[0];
                        });

        int next = j - arr.begin();

        // ---------------- PICK ----------------

        long long pick = arr[i][2] + solve(arr, next, count + 1, intervals);

        vector<int> pickPath = path[next][count + 1];

        pickPath.push_back(arr[i][3]);

        // ---------------- NOT PICK ----------------

        long long notPick = solve(arr, i + 1, count, intervals);

        vector<int> notPickPath = path[i + 1][count];

        // ---------------- CHOOSE ----------------

        if (pick > notPick) {

            path[i][count] = pickPath;

        } else if (notPick > pick) {

            path[i][count] = notPickPath;

        } else {

            sort(pickPath.begin(), pickPath.end());
            sort(notPickPath.begin(), notPickPath.end());

            if (pickPath < notPickPath)
                path[i][count] = pickPath;
            else
                path[i][count] = notPickPath;
        }

        return dp[i][count] = max(pick, notPick);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();
        path = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(5));
        dp = vector<vector<long long>>(n + 1, vector<long long>(5, -1));
        vector<vector<long long>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back(
                {intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(arr.begin(), arr.end());

        solve(arr, 0, 0, intervals);
        vector<int> ans = path[0][0];

        sort(ans.begin(), ans.end());

        return ans;
    }
};