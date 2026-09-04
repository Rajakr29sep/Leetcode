class Solution {
public:
    // took help
    void solve(int i, string& num, long long value, long long prev, string expr,
               int target, vector<string>& ans) {

        if (i == num.size()) {
            if (value == target) {
                ans.push_back(expr);
            }
            return;
        }

        long long curr = 0;

        for (int j = i; j < num.size(); j++) {

            // Leading zero
            if (j > i && num[i] == '0')
                break;

            curr = curr * 10 + (num[j] - '0');

            string part = num.substr(i, j - i + 1);

            // First number
            if (i == 0) {
                solve(j + 1, num, curr, curr, part, target, ans);
            } else {

                // +
                solve(j + 1, num, value + curr, curr, expr + "+" + part, target,
                      ans);

                // -
                solve(j + 1, num, value - curr, -curr, expr + "-" + part,
                      target, ans);

                // *
                solve(j + 1, num, value - prev + prev * curr, prev * curr,
                      expr + "*" + part, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        vector<string> ans;

        solve(0, num, 0, 0, "", target, ans);

        return ans;
    }
};