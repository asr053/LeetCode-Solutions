class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int ans = 1;
        unordered_set<int>st;
        for(auto it:nums)st.insert(it);
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt = 1 , curr =it;
                while(st.find(curr+1)!=st.end()){curr++;cnt++;}
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};