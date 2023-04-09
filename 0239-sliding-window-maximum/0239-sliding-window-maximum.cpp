class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      map<int,int>mp;
        vector<int>res;
        for(int i=0;i<k;i++)mp[nums[i]]++;
        auto it = mp.end(); it--;
        res.push_back((*it).first);
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)mp.erase(nums[i-k]);
            mp[nums[i]]++;
              auto it = mp.end(); it--;
        res.push_back((*it).first);
        }
        return res;
    }
};