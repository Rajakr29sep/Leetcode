class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int k = log2(n) + 1;
        int ans = pow(2, k);
        return ans;
    }
};