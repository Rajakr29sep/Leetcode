class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();

        vector<int> prefixOneS(n);

        int countS0 = s[0] == '0' ? 1 : 0;
        prefixOneS[0] = !countS0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                countS0++;
                prefixOneS[i] = prefixOneS[i - 1];
            } else
                prefixOneS[i] = prefixOneS[i - 1] + 1;
        }

        vector<bool> ans(strs.size());

        for (int i = 0; i < strs.size(); i++) {

            string t = strs[i];

            int count0 = 0;
            int ques = 0;
            for (int j = 0; j < n; j++) {
                if (t[j] == '0')
                    count0++;
                else if (t[j] == '?') {
                    ques++;
                }
            }
            int count1 = n - count0 - ques;
            int need = countS0 - count0;
   bool flag = (count0 > countS0) ||
            (count1 > prefixOneS[n - 1]);

            if (flag) {
                ans[i] = false;
                continue;
            }
            count1 = 0;
            for (int j = 0; j < n; j++) {
                if (t[j] == '1')
                    count1++;

                if (t[j] == '?' && need > 0) {
                    need--;
                } else if (t[j] == '?' && need == 0) {
                    count1++;
                }

                if (prefixOneS[j] < count1) {
                    ans[i] = false;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                ans[i] = true;
        }
        return ans;
    }
};