class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
           map<int,int>mp;
        mp[nums[0]]++;
      for(int i=1;i<=min(k,(int)nums.size()-1);i++){
         if(mp.count(nums[i]))return true;
          mp[nums[i]]++;
      }
    for(int i=k+1;i<nums.size();i++){
        mp[nums[i-k-1]]--;
        if(mp[nums[i-k-1]]==0)mp.erase(nums[i-k-1]);
        if(mp.count(nums[i]))return true;
        mp[nums[i]]++;
    }
          
      return false;
    }
};