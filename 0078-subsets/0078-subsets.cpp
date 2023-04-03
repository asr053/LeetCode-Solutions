class Solution {
public:
    vector<vector<int>>res;
    void fn(int index,vector<int>nums,vector<int>curr){
        if(index==nums.size()){res.push_back(curr);return;}
        fn(index+1,nums,curr);
        curr.push_back(nums[index]);
        fn(index+1,nums,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
      int n = (1<<nums.size())-1;
        for(int i=0;i<=n;i++){
            int ind = 0;
            int k = i;
            vector<int>curr;
            while(k){
                if(k%2)curr.push_back(nums[ind]);
                ind++;k/=2;
            }
            res.push_back(curr);
        }
        return res;
    }
};