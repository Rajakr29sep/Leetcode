
static int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        long long endZero = 0;
        long long endOne = 0;
        int n = binary.size();
        bool hasZero = 0;
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                hasZero = 1;
                endZero = (endZero + endOne) % MOD;
            } else {
                endOne = (endZero + endOne + 1Z) % MOD;
            }
        }
        return (endOne + endZero + (hasZero)) % MOD;
    }
};