class Solution {
public:
    bool check(int val,vector<int>&weights, int days){
        int cnt = 1,curr=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>val)return false;
            if(curr+weights[i]>val){
                cnt++;
                curr=0;
                i--;
            }else curr += weights[i];
        }
        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1 , h = accumulate(weights.begin(),weights.end(),0);
        int ans = h ;
        while(l<=h){
            
            int mid = (l+h)/2;
            if(check(mid,weights,days)){ans = mid;h=mid-1;}
            else l = mid+1;
        }
        return ans;
    }
};