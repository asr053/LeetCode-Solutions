class Solution {
public: vector<vector<int>>res;
    void fn(int index,vector<int>nums,vector<int>curr){
        if(index==nums.size()){res.push_back(curr);return;}
      
        int cnt = 1;
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            cnt++;index++;
        }
        fn(index+1,nums,curr);
        for(int i=1;i<=cnt;i++){
            curr.push_back(nums[index]);
            fn(index+1,nums,curr);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         fn(0,nums,{});
        return res;
    }
};