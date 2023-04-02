class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int sz = arr.size();
        if(arr.size()==1)return 0;
       vector<vector<int>> v(k);
        for(int i=0;i<k;i++){
            for (int j = i; arr[j] != 0; j = (j + k) % sz) {
            v[i].push_back(arr[j]);
            arr[j] = 0;
        }
        }
        long long res = 0;
        for(int i=0;i<v.size();i++){
            sort(v[i].begin(),v[i].end());
            for(int j=0;j<v[i].size();j++){
                res += (abs(v[i][j]-v[i][v[i].size()/2]));
            }
        }
        return res;
    }
};