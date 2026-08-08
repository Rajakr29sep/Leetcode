class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<int> suffix(n + 1, 0);
        int i = n - 1;
        int j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                suffix[i] = suffix[i + 1] + 1;
                j--;
            } else {
                suffix[i] = suffix[i + 1];
            }
            i--;
        }

        i = 0;
        j = 0;
        bool used = false;
        vector<int> ans;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                j++;
                ans.push_back(i);
            } else if (!used && suffix[i + 1] >= (m - j - 1)) {
                j++;
                used = true;
                ans.push_back(i);
            }
            i++;
        }
        if (ans.size() == m)
            return ans;
        return {};
    }
};
