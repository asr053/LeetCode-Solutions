class Solution {
public:
    int adj(vector<int>&arr){
        //vector<vector<int>>v(arr.size(),vector<int>(2,0));
       // v[0][1]=arr[0];
        int a = arr[0],b=0;
        for(int i=1;i<arr.size();i++){
            int d =max(a,b);
            int c=arr[i] + b;
            a = c , b = d;
        }
        return max(a,b);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,0));
      dp[0][1]=nums[0];
        //dp[i][0]->max sum till i when you do not rob at i 
        //dp[i][1]->max sum till i when you rob at day i
        for(int i=1;i<nums.size();i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=(dp[i-1][0]+nums[i]);
        }
      return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};