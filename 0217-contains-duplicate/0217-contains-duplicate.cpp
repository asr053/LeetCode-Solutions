class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto it:nums)if(st.count(it))return true;else st.insert(it);
        return false;
    }
};