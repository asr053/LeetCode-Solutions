class Solution {
public:
    int uniquePaths(int n, int m) {
       swap(n,m);
        int dp[m][n];
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)dp[i][j]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
                 if(i>0) dp[i][j] += dp[i-1][j];
                 if(j>0) dp[i][j] += dp[i][j-1];
             //    cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
   return dp[m-1][n-1];
    }
};