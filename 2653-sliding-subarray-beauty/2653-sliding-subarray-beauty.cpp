class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>curr(101,0);
        for(int i=0;i<k;i++)curr[nums[i]+50]++;
        vector<int>res;
        int total = 0;
        for(int i=0;i<=100;i++){
            if(curr[i]==0)continue;
            total += (curr[i]);
            if(total>=x){
             //   cout<<i<<endl;
                if(i>=50)
                    res.push_back(0);
                else
                res.push_back(i-50);break;
            }
        }
        for(int i=k;i<n;i++){
            curr[nums[i-k]+50]--;
            curr[nums[i]+50]++;
            int total =0;
            for(int j=0;j<=100;j++){
                if(curr[j]==0)continue;
                total+=curr[j];
                if(total>=x){
                    if(j>=50)
                        res.push_back(0);
                    else
                    res.push_back(j-50);break;
                }
            }
        }
        return res;
    }
};