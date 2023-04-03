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
        fn(0,nums,{});
        return res;
    }
};