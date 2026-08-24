class Solution {
public:
    bool sumGame(string num) {
        long long a = 0;
        long long b = 0;
        long long c = 0;
        long long d = 0;

        int i = 0;
        int n = num.length();
        int half = n / 2;

        while (i < half) {
            if (num[i] == '?')
                b++;
            else {
                a += (num[i] - '0');
            }
            i++;
        }
        while (i < n) {
            if (num[i] == '?')
                d++;
            else {
                c += (num[i] - '0');
            }
            i++;
        }

        if ((b + d) % 2 == 1)
            return true;
        int LEFT = 2 * a + 9 * b;

        int RIGHT = 2 * c + 9 * d;
        if (LEFT == RIGHT) 
            return false;

        return true;
    }
};