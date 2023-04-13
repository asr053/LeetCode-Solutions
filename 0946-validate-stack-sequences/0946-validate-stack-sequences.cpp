class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size())return false;
        stack<int>st;
        int i=0,j=0;
        while(i<pushed.size()){
            if(st.size() && st.top()==popped[j]){
                st.pop();j++;
            }else st.push(pushed[i++]);
        }
        while(st.size()){
            if(st.top()==popped[j]){
                st.pop();j++;
            }else return false;
        }
        return true;
    }
};