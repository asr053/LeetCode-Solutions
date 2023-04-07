class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int front=i+1,back=nums.size()-1;
            int target = -nums[i];
            while(front<back){
                 if(nums[front]+nums[back]<target)front++;
                else if(nums[front]+nums[back]>target)back--;
                else{
                    res.push_back({nums[i],nums[front],nums[back]});
                    while(front+1<back && nums[front]==nums[front+1])front++;
                    while(back-1>front && nums[back]==nums[back-1])back--;
                    front++,back--;
                }
            }
               while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
            i++;
        }
        return res;
    }
};