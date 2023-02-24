class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(3,0));
        dp[0][1]=dp[0][2]=(INT_MIN);
        
        for(int i=1;i<=nums.size();i++){
              
              if(nums[i-1]%3==0){
                   dp[i][0]=max(dp[i-1][0],nums[i-1]+dp[i-1][0]);
                  dp[i][1]=max(dp[i-1][1],nums[i-1]+dp[i-1][1]);
                   dp[i][2]=max(dp[i-1][2],nums[i-1]+dp[i-1][2]);
              }else if(nums[i-1]%3==1){
                  dp[i][0]=max(dp[i-1][0],nums[i-1]+dp[i-1][2]);
                  dp[i][1]=max(dp[i-1][1],nums[i-1]+dp[i-1][0]);
                  dp[i][2]=max(dp[i-1][2],nums[i-1]+dp[i-1][1]);
              }else{
                  dp[i][0]=max(dp[i-1][0],nums[i-1]+dp[i-1][1]);
                  dp[i][1]=max(dp[i-1][1],nums[i-1]+dp[i-1][2]);
                  dp[i][2]=max(dp[i-1][2],nums[i-1]+dp[i-1][0]);
              }
           // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        
        return dp[nums.size()][0];
    }
};