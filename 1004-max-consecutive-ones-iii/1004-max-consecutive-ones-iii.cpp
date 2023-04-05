class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        queue<int>q;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(q.size()==k+1){q.pop();}
                q.push(i);
            }
            if(q.size()==k+1){res=max(res,i-q.front());}
            else res = max(res,i+1);
            
        }
        return res;
    }
};