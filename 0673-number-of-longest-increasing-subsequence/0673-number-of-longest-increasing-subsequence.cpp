class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector <int> dplen(n, 0);
        vector <int> dpcount(n, 0);
        dplen[0] = 1;
        dpcount[0] = 1;

        int maxlen = 1;
        int maxcount = 1;

        for(int i=1; i<n; i++){
            int ilen = 1, icount = 1;
            
            for(int j=0; j<i; j++){
                if (nums[j] < nums[i]){
                    if (dplen[j]+1 > ilen){
                        ilen = dplen[j]+1;
                        icount = dpcount[j];
                    }
                    else if (dplen[j]+1 == ilen){
                        icount += dpcount[j];
                    }
                    
                }
            }
            
            dplen[i] = ilen;
            dpcount[i] = icount;

            if(maxlen<ilen){
                maxlen = ilen;
                maxcount = icount;
            }
            else if(maxlen==ilen){
                maxcount += icount;
            }
        }

        return maxcount;
    }
};