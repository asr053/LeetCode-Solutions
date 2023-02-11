class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
     int cnt = 0;
        map<int,int>mp;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            if(mp.count(total-k))cnt += mp[total-k];
             if(total==k)cnt++;
            mp[total]++;
        }
        return cnt;
    }
};