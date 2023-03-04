class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int curr = 0 , res =0 ;
        for(auto it:nums){
            curr += it;
             if(mp.count(curr-k))res += mp[curr-k];
             mp[curr]++;
        }
        return res;
    }
};