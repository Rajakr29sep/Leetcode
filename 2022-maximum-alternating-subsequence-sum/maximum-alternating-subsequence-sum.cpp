class Solution {
public:

    // long long solve(vector<int>& nums, int i , bool isEven,vector<vector<long long>>&dp){
    //     if(i == nums.size()){
    //         return 0;
    //     }
    //     if(dp[i][isEven]!=-1)return dp[i][isEven];
    //     long long notPick = solve(nums,i+1,isEven,dp);
    //     long long pick =LLONG_MIN;
    //     if(isEven){
    //      pick = nums[i]+solve(nums,i+1,!isEven,dp);
    //     }
    //     else{
    //         pick = -nums[i]+solve(nums,i+1,!isEven,dp);
            
    //     }
    //     return dp[i][isEven]=max(pick,notPick);
    // }

    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));

        for(int i=n-1; i>=0; i--){
            for(int j =0; j<=1; j++){
                long long pick =LLONG_MIN;
                long long notPick = dp[i+1][j];
                if(j){
                    pick = 1LL*nums[i]+dp[i+1][!j];
                }
                else{
                    pick = -1LL*nums[i]+dp[i+1][!j];
                }

                dp[i][j] = max(pick,notPick);
            }
        }
        return max(dp[0][0],dp[0][1]);
    }
};