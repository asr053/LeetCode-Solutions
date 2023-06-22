class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int>prvs(2,0);
        
        for(int ind = prices.size()-1;ind>=0;ind--){
            vector<int>curr(2,0);
            for(int buy=0;buy<=1;buy++){
                if(buy){
                     curr[1]=max(-prices[ind]+prvs[0],prvs[1]);
                }else{
                     curr[0]=max(prices[ind]+prvs[1]-fee,prvs[0]);
                }
            }
            prvs=curr;
        }
        return prvs[1];
    }
};