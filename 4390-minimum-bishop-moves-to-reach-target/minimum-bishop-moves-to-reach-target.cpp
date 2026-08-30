class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int i = source[0];
        int j = source[1];

        int s = target[0];
        int e = target[1];

        int sum1 = i + j;
        int sum2 = s + e;
        int diff1 = abs(i - s);
        int diff2 = abs(j - e);
        if (sum1 % 2 != sum2 % 2) {
            return -1;
        }
        if (sum1 == sum2 || diff1 == diff2)
            return 1;

        return 2;
    }
};