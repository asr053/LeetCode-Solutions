class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        int res = 0 , n = c.size();
        for(int i=c.size()-1;i>=0;i--){
            if(c[i]>=n-i)res = max(res,(n-i));
        }
        return res;
    }
};