class Solution {
public:
    int majorityElement(vector<int>& arr) {
         int res = 0 , count = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[res]==arr[i]){
                count++;
            }else{
                count--;
            }
            if(count==0){
                count = 1 ;
                res = i;
            }
        }
               return arr[res];
    }
};