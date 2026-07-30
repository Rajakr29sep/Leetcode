class Solution {
public:
    bool solve(vector<int>& nums, int i, int j, int turn, int score1,
               int score2) {
        if (i > j)
            return score1 >= score2;

        if (i == j) {
            if (turn == 0)
                score1 += nums[i];
            else
                score2 += nums[i];

            return score1 >= score2;
        }
        bool flag1 = false;
        bool flag2 = false;
        if (turn == 0) {
            flag1 = solve(nums, i + 1, j, 1, score1 + nums[i], score2);
            flag2 = solve(nums, i, j - 1, 1, score1 + nums[j], score2);
            return  flag1 || flag2;

        } else {
            flag1 = solve(nums, i + 1, j, 0, score1, score2 + nums[i]);
            flag2 = solve(nums, i, j - 1, 0, score1, score2 + nums[j]);
            return flag1 && flag2;
        }
        return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1, 0, 0, 0);
    }
};