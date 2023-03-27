class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        dp[0][0]=grid[0][0];
        for(int j=1;j<grid[0].size();j++)dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                  int first = INT_MAX , second = INT_MAX;
                if(j>0)first = min(first,dp[i][j-1]);
                second = min(second,dp[i-1][j]);
                dp[i][j]=min(first,second)+grid[i][j];
            }
        }
      return dp[grid.size()-1][grid[0].size()-1];
    }
};