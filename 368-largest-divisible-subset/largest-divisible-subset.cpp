class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int m = nums.size();
        int maxi = 0;
        vector<int> hash(m);
        vector<int> t(m, 1);
        int lastidx = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < m; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && t[j] + 1 > t[i]) {
                    hash[i] = (j);
                    t[i] = t[j] + 1;
                }
            }
            if (t[i] > maxi) {
                maxi = t[i];
                lastidx = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastidx]);
        while (hash[lastidx] != lastidx) {
            lastidx = hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};