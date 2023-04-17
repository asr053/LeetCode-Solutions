class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ec) {
        vector<bool>v;
        int n=candies.size();
        int mxm=*max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++) v.push_back(candies[i]+ec>=mxm);
        return v;
    }
};