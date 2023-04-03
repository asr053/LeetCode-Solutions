class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int d) {
      map<int,int>mp;
        mp[nums[0]]++;
      for(int i=1;i<=min(k,(int)nums.size()-1);i++){
          auto it1 = mp.lower_bound(nums[i]-d);
          if(it1==mp.end())it1--;
          if((*it1).first>=nums[i]-d && (*it1).first<=nums[i]+d)return true;
          mp[nums[i]]++;
      }
    for(int i=k+1;i<nums.size();i++){
        mp[nums[i-k-1]]--;
        if(mp[nums[i-k-1]]==0)mp.erase(nums[i-k-1]);
         auto it1 = mp.lower_bound(nums[i]-d);
          if(it1==mp.end())it1--;
          if((*it1).first>=nums[i]-d && (*it1).first<=nums[i]+d)return true;
        mp[nums[i]]++;
    }
          
      return false;
    }
};