class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            if (mp.find(row) == mp.end()) {
                mp[row] = vector<int>(11, 0);
            }

            mp[row][seat] = 1;
        }
        int ans = 0;
        for (auto& it : mp) {

            bool left = it.second[2] == 0 && it.second[3] == 0 &&
                        it.second[4] == 0 && it.second[5] == 0;

            bool middle = it.second[4] == 0 && it.second[5] == 0 &&
                          it.second[6] == 0 && it.second[7] == 0;

            bool right = it.second[6] == 0 && it.second[7] == 0 &&
                         it.second[8] == 0 && it.second[9] == 0;

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }
        int k = mp.size();
        ans += (n - k) * 2;
        return ans;
    }
};