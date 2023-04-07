class Solution {
public:
    vector<vector<int>>res;
    void fn(vector<int>nums,vector<int>curr,vector<int>vis){
        if(curr.size()==nums.size()){res.push_back(curr);return;}
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){vis[i]=1;curr.push_back(nums[i]);fn(nums,curr,vis);curr.pop_back();vis[i]=0;}
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        fn(nums,{},vis);
        return res;
    }
};