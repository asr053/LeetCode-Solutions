class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(st.size()==0)st.push(it);
            else{
                if(st.top()=='(' && it==')')st.pop();
                else if(st.top()=='{' && it=='}')st.pop();
                else if(st.top()=='[' && it==']')st.pop();
                else st.push(it);
            }
        }
        return (!st.size());
    }
};