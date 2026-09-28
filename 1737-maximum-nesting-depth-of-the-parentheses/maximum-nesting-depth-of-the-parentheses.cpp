class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int maxi = 0;
        for (auto& ch : s) {
            if (ch == '(') {
                ans++;
                maxi = max(ans, maxi);
            } else if (ch == ')') {
                ans--;
            }
        }
        return maxi;
    }
};
