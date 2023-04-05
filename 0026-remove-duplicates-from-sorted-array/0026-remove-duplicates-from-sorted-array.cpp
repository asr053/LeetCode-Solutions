class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        int i =0 , j = 0;
        while(j<nums.size()){
            nums[i]=nums[j];k++;
            while(j<nums.size() && nums[j]==nums[i])
j++;i++;        }
        return k;
    }
};