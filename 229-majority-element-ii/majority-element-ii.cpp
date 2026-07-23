class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = INT_MIN;
        int cnt1 = 0;
        int elem2 = INT_MIN;
        int cnt2 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != elem2) {
                elem1 = nums[i];
                cnt1++;
            } else if (cnt2 == 0 && nums[i] != elem1) {
                elem2 = nums[i];
                cnt2++;
            } else if (elem1 == nums[i]) {
                cnt1++;
            } else if (elem2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (auto& it : nums) {
            if (it == elem1)
                cnt1++;
            if (it == elem2)
                cnt2++;
        }

        vector<int> ans;
        if (cnt1 > n / 3 && cnt2 > n / 3)
            ans = {elem1, elem2};
        else if (cnt1 > n / 3) {
            ans = {elem1};
        } else if (cnt2 > n / 3) {
            ans = {elem2};
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};