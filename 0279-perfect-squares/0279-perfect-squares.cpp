class Solution {
public:
    int numSquares(int n) {
        int x = sqrt(n);
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++)dp[i]=i;
        for(int i=1;i<=n;i++){
            int val=dp[i];
            for(int j=1;j*j<=i;j++){
                val = min(val,1+dp[i-j*j]);
            }
            dp[i]=min(dp[i],val);
        }
        return dp[n];
    }
};