class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = "";

        // First try to match target as much as possible
        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Same character available
            if (count[x] > 0) {
                ans += target[i];
                count[x]--;
            } else {
                // Same character unavailable.
                // Need a greater character here.
                int greater = -1;

                for (int j = x + 1; j < 26; j++) {
                    if (count[j] > 0) {
                        greater = j;
                        break;
                    }
                }

                if (greater != -1) {
                    ans += char('a' + greater);
                    count[greater]--;

                    // Append remaining chars in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (count[j] > 0) {
                            ans += char('a' + j);
                            count[j]--;
                        }
                    }

                    return ans;
                }

                // No greater char.
                // We need to backtrack.
                break;
            }
        }
     
        // Backtracking
        for (int i = ans.size() - 1; i >= 0; i--) {

            // Put back ans[i]
            count[ans[i] - 'a']++;

            int x = target[i] - 'a';

            // Find smallest character > target[i]
            for (int j = x + 1; j < 26; j++) {

                if (count[j] > 0) {

                    string result = target.substr(0, i);
                    result += char('a' + j);

                    count[j]--;

                    // Add remaining characters smallest first
                    for (int k = 0; k < 26; k++) {
                        while (count[k] > 0) {
                            result += char('a' + k);
                            count[k]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};