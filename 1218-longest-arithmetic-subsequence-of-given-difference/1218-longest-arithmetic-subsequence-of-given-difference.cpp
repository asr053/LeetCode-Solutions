class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
         vector<int>dp(2*(1e5)+10,0);
      
        int n = arr.size();
          for(int i=0;i<n;i++)arr[i]+=(10000);
        for(int i=0;i<n;i++){
            
            if(diff==0)dp[arr[i]]++;
            else
            {if(dp[arr[i]]==0)dp[arr[i]]=1;
             if(arr[i]-diff>=0)dp[arr[i]]=max(dp[arr[i]],1+dp[arr[i]-diff]);}
            //cout<<1+dp[arr[i]-diff]<<endl;
        }
       // cout<<dp[1]<<dp[2]<<dp[3]<<dp[4]<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};