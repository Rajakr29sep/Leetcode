class Solution {
public:

int t[501][501] ;
    int solve(vector<int>& nums, int i, int j) {
        if (i > j)
            return 0;

        if (i == j) {
            return nums[i];
        }
        if(t[i][j]!=-1) return t[i][j];
            int take_i = nums[i]-solve(nums, i + 1, j);
            int take_j = nums[j]-solve(nums, i, j - 1 );

        return t[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        //leetcode -486
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, 0, n - 1)>=0;

    }

    bool stoneGame(vector<int>& piles) {
       return predictTheWinner(piles); 
    }
};