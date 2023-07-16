class Solution {
public:
    int req;
    int rec(int ind,int mask,vector<int>&p,vector<vector<int>>&dp,vector<vector<int>>&choices)
    {
        if (mask==req) return 0;
        if (ind==p.size()) return 1e7;
        if (dp[ind][mask]!=-1) return dp[ind][mask];
        int pick=1+rec(ind+1,mask|p[ind],p,dp,choices);
        int notPick=rec(ind+1,mask,p,dp,choices);
        if (pick<notPick)
        choices[ind][mask]=1;
        return dp[ind][mask]=min(pick,notPick);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        int n=req_skills.size();
        req=(1<<n)-1;
        unordered_map<string,int>mp;
        for (int i=0;i<n;i++)
        {
            mp[req_skills[i]]=(1<<i);
        }
        vector<int>p;
        for (int i=0;i<people.size();i++)
        {
            int temp=0;
            for (int j=0;j<people[i].size();j++)
            {
                temp|=mp[people[i][j]];
            }
            p.push_back(temp);
        }
        int sz=people.size();
        vector<vector<int>>dp(sz,vector<int>((1<<n),-1));
        vector<vector<int>>choices(sz,vector<int>((1<<n),0));
        rec(0,0,p,dp,choices);
        vector<int>ans;
        for (int i=0,mask=0;i<p.size();i++)
        {
            if (choices[i][mask])
            {
              ans.push_back(i);
              mask|=p[i];
            }
            if (mask==req) return ans;
        }
        return ans;
    }
};