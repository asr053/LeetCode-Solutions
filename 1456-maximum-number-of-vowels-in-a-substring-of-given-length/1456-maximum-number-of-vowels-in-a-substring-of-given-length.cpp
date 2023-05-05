class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0 , res = 0;
        for(int i=0;i<s.size();i++){
            cnt += (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u');
            if(i>=k) cnt -= (s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u');
            res = max(res,cnt);
        }
        return res;
    }
};