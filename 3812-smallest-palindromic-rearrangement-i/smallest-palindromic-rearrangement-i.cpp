class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> store(26, 0);
        for (auto& it : s) {
            store[it - 'a']++;
        }
        string start = "";
        string ends = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if ((store[i]%2) == 1) {
                middle = 'a'+i;
                store[i]--;
                i--;
            } else if(store[i]%2==0) {
                while(store[i]){
                start += ('a' + i);
                ends += ('a' + i);
                store[i]-=2;
                }
            }
        }

        reverse(ends.begin(), ends.end());
        start += middle;
        start += ends;
        return start;
    }
};