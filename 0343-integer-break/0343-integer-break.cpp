class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        for(int i=2;i<=n;i++)dp[i]=i-2;
        for(int i=2;i<=n;i++){
            int ans = i-2;
            for(int j=1;j<=i/2;j++){
              ans = max({ans,(j)*(i-j),dp[j]*(i-j),dp[i-j]*j,dp[i-j]*dp[j]})   ;
            }
            dp[i]=ans;
        }
        return dp[n];
    }
};