class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int ind =  lower_bound(nums.begin(),nums.end(),target)-nums.begin();
       if(ind==nums.size())return nums.size();
        return ind;
    }
};