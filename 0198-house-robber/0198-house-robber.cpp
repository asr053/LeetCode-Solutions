class Solution {
public:
    int adj(vector<int>&arr){
        //vector<vector<int>>v(arr.size(),vector<int>(2,0));
       // v[0][1]=arr[0];
        int a = arr[0],b=0;
        for(int i=1;i<arr.size();i++){
            int d =max(a,b);
            int c=arr[i] + b;
            a = c , b = d;
        }
        return max(a,b);
    }
    int rob(vector<int>& nums) {
         
        return adj(nums);
    }
};