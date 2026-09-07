class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        int n = s.length();
        vector<long long> last(26, 0);

        long long dp = 2;
        last[s[0] - 'a'] = 1;
        // stores the number of distinct non-empty subsequences that were
        // newly generated when the previous occurrence of character c
        // was processed.

        for (int i = 1; i < n; i++) {
            int c = s[i] - 'a';

            long long add = dp;

            dp = (2 * add - last[c] + MOD) % MOD;

            // mltiply by 2means including previous everything is
            // appended by current but  there will be  duplicate of
            // prev subseq hence delete last subseq

            //             In this code, last[c] means:

            // How many new distinct subsequences were generated the last time
            // character c appeared.

            // For example, s = "aba":

            // First 'a' → generates "a" → last['a'] = 1
            // 'b' → generates "b", "ab" → last['b'] = 2
            // Second 'a' → last['a'] = 1, so we subtract 1 duplicate.

            last[c] = add;
        }

        return (dp - 1 + MOD) % MOD;
    }
};