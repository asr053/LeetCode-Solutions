class Solution {
public:
    int minSteps(int n) {
        if(n==0 || n==1)return 0;
        if(n==2)return 2;
        int dp[n+1];
        dp[0]=0, dp[1]=0;
          dp[2]=2;
        for(int i=3;i<=n;i++){
            int val = i;
            for(int j=2;j<=i/2;j++){
                if(i%j==0)val = min(val,dp[j]+i/j);
             //   if(val==6 && i==10){cout<<i<<" "<<j<<endl;return val;}
            }
            dp[i]=val;
        }
      
        return dp[n];
    }
};