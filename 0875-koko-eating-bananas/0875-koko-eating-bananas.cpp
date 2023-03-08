class Solution {
public:
bool fn(vector<int>&piles,int h,int m){
    long long curr = 0;
    for(auto it:piles)curr+=(it+m-1)/m;
    return (curr<=h);
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, high = 1e9;
        int ans = -1;
        while(l<=high){
            int m = (high-l)/2 + l;
            if(fn(piles,h,m)){
                ans = m;
                high = m-1;
            }else l = m+1;
           // cout<<l<<" "<<high<<endl;
        }
        return ans;
    }
};