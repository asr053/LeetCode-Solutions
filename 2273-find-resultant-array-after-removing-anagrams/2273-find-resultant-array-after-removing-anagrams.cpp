class Solution {
public:
    vector<string> removeAnagrams(vector<string>& word) {
         stack<string>st;
         st.push(word[0]);
         for(int i=1;i<word.size();i++){
             string last = st.top();
             string curr = word[i];
             sort(last.begin(),last.end());sort(curr.begin(),curr.end());
             if(curr==last)continue;
             else st.push(word[i]);
         }
         vector<string>v;
         while(st.size()){
             v.push_back(st.top());
             st.pop();
         }
         reverse(v.begin(),v.end());
         return v;
    }
};