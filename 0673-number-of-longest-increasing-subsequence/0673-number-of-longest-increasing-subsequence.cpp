class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(),{0,0});
        dp[0]={1,1};
        for(int i=1;i<nums.size();i++){
             dp[i]={1,1};
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    //   if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    // if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
                      if(dp[j].first+1==dp[i].first)dp[i].second+=dp[j].second;
                   else if(dp[j].first+1>dp[i].first){dp[i]=dp[j];dp[i].first++;}
                   
                }
            }
        }
        int re = 0, len = 0;
        for(auto it:dp){
            if(it.first>len)len=it.first,re=it.second;
            else if(it.first==len)re+=it.second;
        }
        return re;
    }
};