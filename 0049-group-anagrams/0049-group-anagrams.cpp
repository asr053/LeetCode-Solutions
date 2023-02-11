class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(auto it:strs){
            vector<int>cnt(26,0);
            for(auto i:it)cnt[i-'a']++;
            mp[cnt].push_back(it);
            
        }
        vector<vector<string>>res;
        for(auto it:mp){
            vector<string>curr;
            for(auto i:it.second)curr.push_back(i);
            res.push_back(curr);
        }
        return res;
    }
};