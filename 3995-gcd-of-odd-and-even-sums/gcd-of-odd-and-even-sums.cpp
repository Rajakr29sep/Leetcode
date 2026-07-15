class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = n * n;
        long long sumEven = (n * (n + 1));
        // cout<<sumOdd <<"  "<<sumEven<<endl;
        return __gcd(sumOdd, sumEven);
    }
};