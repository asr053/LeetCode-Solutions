class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0 , j = strs[0].size();
        for(int i=1;i<strs.size();i++){
            int k=0;
            for(;k<strs[i].size();k++){
                if(strs[0][k]!=strs[i][k])break;
            }
            j = min(j,k);
        }
        return strs[0].substr(0,j);
    }
};