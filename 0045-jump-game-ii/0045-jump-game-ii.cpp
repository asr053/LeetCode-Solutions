class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),INT_MAX);
        dp[0]=0;
        for(int i=1;i<nums.size();i++){
             for(int j=1;j<=1000;j++){
                 if(i-j<0)break;
               if(i-j+nums[i-j]>=i)    dp[i]=min(dp[i-j]+1,dp[i]);
             }
        }
        return dp.back();
    }
};