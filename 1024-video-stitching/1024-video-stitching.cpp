class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
         int n = clips.size();
        vector<int> dp(T+2,T+1);
        dp[0] = 0;
        for(int i=0;i<=T;i++){
            for(auto clip : clips){
                if(clip[0] <= i && i <= clip[1]){
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
            if(dp[i] >= T+1) return -1;
        }
        return dp[T];
    }
};