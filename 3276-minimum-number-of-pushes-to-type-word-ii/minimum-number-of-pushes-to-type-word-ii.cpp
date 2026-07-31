class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> alpha(26, 0);
        for (int i = 0; i < n; i++) {
            alpha[word[i] - 'a']++;
        }
        int total = 0;
        sort(alpha.begin(), alpha.end(), greater<int>());

        for (int i = 0; i < 26; i++) {
            if (i < 8) {
                total += alpha[i];
            } else if (i < 16) {
                total += (alpha[i] * 2);
            } else if (i < 24) {
                total += (alpha[i] * 3);
            } else if (i < 26) {
                total += (alpha[i] * 4);
            }
        }
        return total;
    }
};