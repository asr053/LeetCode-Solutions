class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
       long ans = INT_MIN;
        long curr = 0;
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            ans = max(ans,(curr+i)/(i+1));
        }
        return ans;
    }
};