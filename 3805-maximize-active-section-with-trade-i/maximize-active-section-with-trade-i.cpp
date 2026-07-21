class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int total = 0;
        int n = s.length();
        vector<int> zero;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                total++;
            } else if (s[i] == '0') {
                int count = 0;
                while (i < n && s[i] == '0') {
                    i++;
                    count++;
                }
                zero.push_back(count);
                i--;
            }
        }
        if(total==n)return total;
        int ans = 0;
        for (int i = 1; i < zero.size(); i++) {
            ans = max(ans, zero[i] + zero[i - 1]);
        }
        return ans + total;
    }
};