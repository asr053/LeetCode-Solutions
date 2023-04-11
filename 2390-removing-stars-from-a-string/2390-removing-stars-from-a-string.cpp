class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='*'){
                if(st.size()&& isalpha(st.top()))st.pop();
                else st.push(it);
            }else{
                if(st.size() && st.top()=='*')st.pop();
                else st.push(it);
            }
        }
        string curr = "";
        while(st.size()){
            curr +=st.top();st.pop();
        }
        reverse(curr.begin(),curr.end());
        return curr;
    }
};