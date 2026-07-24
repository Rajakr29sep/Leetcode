class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pairXor(2048, 0);
        vector<int> tripletXor(2048, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int ans = nums[i] ^ nums[j];
                pairXor[ans]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2048; j++) {

                if (pairXor[j] != 0) {
                    int temp = j ^ nums[i];
                    // if(xorValue[temp]!=0){
                    tripletXor[temp] = 1;
                    // }
                }
            }
        }
        int ans = 0;

        for (int i = 0; i < 2048; i++) {
            if (tripletXor[i] >= 1)
                ans++;
        }

        return ans;
    }
};