class Solution {
public:
    int f(string word1, string word2 , int i , int j,vector<vector<int>> &dp){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i-1]==word2[j-1])return f(word1,word2,i-1,j-1,dp);
        else {
            return dp[i][j]=1 + min({f(word1,word2,i-1,j,dp),f(word1,word2,i,j-1,dp),f(word1,word2,i-1,j-1,dp)});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return f(word1, word2, word1.size(),word2.size(),dp);
    }
};