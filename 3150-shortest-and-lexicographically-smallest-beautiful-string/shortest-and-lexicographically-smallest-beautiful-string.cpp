class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int i = 0;
        int j = 0;
        int n = s.length();
        int count = 0;
        string ans = "";
        while (j < n) {
            if (s[j] == '1') {
                count++;
            }
            while (i <= j && count > k) {
                if (s[i] == '1') {
                    count--;
                }
                i++;
            }

            if (count == k) {
                while (i < j && s[i] == '0') // remove leading zero
                    i++;
                if (j - i + 1 < ans.length() || ans == "") {
                    ans = s.substr(i, j - i + 1);
                } else if (j - i + 1 == ans.length()) {
                    ans = min(ans, s.substr(i, j - i + 1));
                }
            }
            j++;
        }
        return ans;
    }
};