class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int res = 1;
        for(auto it:s){
            if(st.count(it)){
                st.clear(); res++;
            }
            st.insert(it);
        }
        return res;
    }
};