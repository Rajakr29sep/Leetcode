class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stack<char> st;
        int n = s.length();
        unordered_map<string, string> mp;
        int m = knowledge.size();
        for (int i = 0; i < m; i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        
        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                string key = "";

                i++; // move after '('

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.find(key) != mp.end())
                    ans += mp[key];
                else
                    ans += '?';
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};