class Solution {
public:
    vector<int> dp;
    int solve(int i, string &s, vector<int>& isPal) {
        if (i >= s.length())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int pick = INT_MIN;
        if (isPal[i] != -1 && i + isPal[i] - 1 < s.length()) {
            pick = 1 + solve(i + isPal[i], s, isPal);
        }
        int notPick = solve(i + 1, s, isPal);
        return dp[i] = max(pick, notPick);
    }
    bool isPalindrome(string &  s ,int i1, int j1) {
        int i = i1;
        int j = j1;

        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
    int maxPalindromes(string s, int k) {

        int n = s.length();
        vector<int> isPal(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + k - 1; j < n; j++) {
                if (j - i + 1 >= k && isPalindrome(s, i, j)) {
                    isPal[i] = j - i + 1;
                    break;
                }
            }
        }

        dp.assign(n + 1, -1);
        return solve(0, s, isPal);
    }
};