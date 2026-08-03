class Solution {
public:
    long long t[50001];
    long long solve(vector<int>& nums, int i, vector<long long>& prefix) {
        if (i >= nums.size())
            return 0;
        if (t[i] != LLONG_MIN)
            return t[i];
        long long maxi = LLONG_MIN;
        for (int k = i; k < min(i + 3, (int)nums.size()); k++) {

            maxi = max(maxi, prefix[k] - (i > 0 ? prefix[i - 1] : 0) -
                                 solve(nums, k + 1, prefix));
        }
        return t[i] = maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> prefix(n);
        prefix[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }
        fill(t, t + 50001, LLONG_MIN);
        long long diff = solve(stoneValue, 0, prefix);
        if (diff > 0)
            return "Alice";
        if (diff < 0)
            return "Bob";
        return "Tie";
    }
};