class Solution {
public:

    long long solve(vector<int>& nums, int i , bool isEven,vector<vector<long long>>&dp){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][isEven]!=-1)return dp[i][isEven];
        long long notPick = solve(nums,i+1,isEven,dp);
        long long pick =LLONG_MIN;
        if(isEven){
         pick = nums[i]+solve(nums,i+1,!isEven,dp);
        }
        else{
            pick = -nums[i]+solve(nums,i+1,!isEven,dp);
            
        }
        return dp[i][isEven]=max(pick,notPick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return solve(nums,0,1,dp);
    }
};