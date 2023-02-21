class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int l = 0 , h = nums.size()-1;
        int add[]={1,-1};
        while(l<=h){
            int mid = (l+h)/2;
                if(nums[mid]==nums[mid+add[mid%2]])l = mid+1;
                else h = mid-1;
        }
        return nums[l];
    }
};