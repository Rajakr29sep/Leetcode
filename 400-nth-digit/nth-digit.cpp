class Solution {
public:
    int findNthDigit(int n) {

        long long len = 1;
        long long startingNumber = 1;

        // Find the digit-length group
        while (n > 9 * startingNumber * len) {
            n -= 9 * startingNumber * len;

            startingNumber *= 10;
            len++;
        }

        int number = startingNumber + (n - 1) / len;
        int digitIndex = (n - 1) % len;
        string s = to_string(number);
        int ans = s[digitIndex] - '0';
        cout << startingNumber << " " << number << " " << s << endl;

        return ans;
    }
};