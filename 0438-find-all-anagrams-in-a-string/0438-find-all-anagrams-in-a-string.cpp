class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())return {};
        vector<int>vis(26,0);
        for(auto it:p)vis[it-'a']++;
        vector<int>curr(26,0);
        for(int i=0;i<min(s.size(),p.size());i++){
            curr[s[i]-'a']++;
        }
        vector<int>res;
        if(vis==curr)res.push_back(0);
        for(int i=1;i<s.size()-p.size()+1;i++){
            curr[s[i-1]-'a']--;
            curr[s[i+p.size()-1]-'a']++;
            if(curr==vis)res.push_back(i);
        }
        return res;
    }
};