class Solution {
public:
    bool solve(int n, int t) {
        int temp = 1;
        while (n) {
            temp = temp* (n % 10);
            n = n / 10;
        }
        return temp % t == 0;
    }

    int smallestNumber(int n, int t) {

        while (1) {
            if (solve(n, t))
                return n;
            n++;
        }
        return n;
    }
};