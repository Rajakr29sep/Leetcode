class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        unordered_set<int> st2;
        for (int i = 0; i < n; i++) {
            for (auto& it : st) {
                st2.insert(nums[i] ^ it);
            }
        }
        st.erase(st.begin(), st.end());

        for (int i = 0; i < n; i++) {
            for (auto& it : st2) {
                st.insert(nums[i] ^ it);
            }
        }
        return st.size();
    }
};