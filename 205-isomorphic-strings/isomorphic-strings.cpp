// linkedin
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        string ans = "";

        for (int i = 0; i < t.length(); i++) {
            char s1 = s[i];
            char s2 = t[i];
            if (mp1.find(s1) == mp1.end() && mp2.find(s2) == mp2.end()) {
                mp1[s1] = s2;
                mp2[s2] = s1;
            } else if ((mp1.find(s1) != mp1.end() &&
                        mp2.find(s2) == mp2.end()) ||
                       (mp1.find(s1) == mp1.end() &&
                        mp2.find(s2) != mp2.end()) ||
                       (mp1[s1] != s2) || (mp2[s2] != s1))
                return false;
        }
        return true;
    }
};