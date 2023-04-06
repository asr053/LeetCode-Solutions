class Solution {
public:
    vector<vector<int>>res;
    void fn(int ind, int target, vector<int>candidates,vector<int>curr,int sum){
        if(ind==candidates.size()){
            if(sum==target)res.push_back(curr);
            return;
        }
        if(sum>target)return;
        int cnt = 0,i=ind;
        while(ind<candidates.size() && candidates[ind]==candidates[i]){
            ind++;cnt++;
        }
        for(int j=0;j<=cnt;j++){
            if(j)curr.push_back(candidates[i]);
            fn(ind,target,candidates,curr,sum+candidates[i]*j);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        fn(0,target,candidates,{},0);
        return res;
    }
};