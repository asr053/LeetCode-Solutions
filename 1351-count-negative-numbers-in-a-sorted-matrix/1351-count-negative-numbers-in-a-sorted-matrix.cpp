class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto it:grid){
            for(auto i:it){
                cnt+=(i<0);
            }
        }
        return cnt;
    }
};