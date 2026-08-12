class Solution {
public:
    int longestSubstring(string s, int k) {

        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                if (mp[s[j]] >= k) {
                    st.insert(s[j]);
                }
                if (mp.size() == st.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};