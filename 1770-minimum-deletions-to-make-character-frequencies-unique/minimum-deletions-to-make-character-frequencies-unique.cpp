class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                while (count[i] > 0 && mp.find(count[i]) != mp.end()) {
                    ans++;
                    count[i]--;
                }
                mp[count[i]]++;
            }
        }
        return ans;
    }
};