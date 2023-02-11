class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>st(nums.begin(),nums.end());
        int res = 0;
        for(auto it:nums){
            if(!st.count(it))continue;
            int n = it;
            st.erase(n);
            int prvs = n-1, next = n+1;
            while(st.size() && st.count(prvs))st.erase(prvs),prvs--;
            while(st.size() && st.count(next))st.erase(next),next++;
            res = max(res,next-prvs-1);
        }
        return res;
    }
};