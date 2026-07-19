class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> taken(26, 0);

        string ans = "";

        stack<char> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && st.top() > s[i] && !taken[s[i] - 'a']) {
                char ch = st.top();
                bool flag = false;
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == ch) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    st.pop();
                    taken[ch - 'a'] = 0;
                } else {
                    break;
                }
            }
            if (!taken[s[i] - 'a']) {
                st.push((s[i]));
                taken[s[i] - 'a'] = 1;
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};