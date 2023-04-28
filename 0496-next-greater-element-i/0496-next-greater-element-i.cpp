class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
        stack<int>st;
       for(auto it:nums2){
           while(st.size() && st.top()<it){
               mp[st.top()]=it;
               st.pop();
           }
           st.push(it);
       }
       vector<int>res;
        for(auto it:nums1){
            if(mp.count(it))res.push_back(mp[it]);
            else res.push_back(-1);
        }
        return res;
    }
};