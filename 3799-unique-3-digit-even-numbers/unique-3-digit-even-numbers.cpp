class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            freq[digits[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < 10; i = i + 2) {
            if (freq[i] == 0)
                continue;
            freq[i]--;

            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j]--;
                for (int k = 1; k < 10; k++) {
                    if (freq[k] > 0) {
                        ans++;
                    }
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return ans;
    }
};