class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0]=-prices[0];
        for(int i=1;i<prices.size();i++){
            //buy
            dp[i][0]=max(-prices[i]+dp[i-1][1],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};