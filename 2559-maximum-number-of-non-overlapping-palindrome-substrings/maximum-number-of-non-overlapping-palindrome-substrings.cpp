class Solution {
public:
    bool isPalindrome(string& s, int i1, int j1) {
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

        vector<int> dp(n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int pick = INT_MIN;
            if (isPal[i] != -1 && i + isPal[i] - 1 <= n) {
                pick = 1 + dp[i + isPal[i]];
            }
            int notPick = dp[i + 1];
            dp[i] = max(pick, notPick);
        }
        return dp[0];
    }
};