class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int elem = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            while (nums[i] != (elem + 1)) {
                result.push_back(elem + 1);
                elem++;
            }
            elem++;
        }
        return result;
    }
};