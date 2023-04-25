class Solution {
public:
     int lastStoneWeight(vector<int>& A) {
         sort(A.begin(),A.end());
         while(A.size()>1){
             int x = A.back();A.pop_back();
             int y = A.back();A.pop_back();
             if(x!=y){A.push_back(abs(x-y));}
             sort(A.begin(),A.end());
         }
         return (A.size()?A[0]:0);
    }
};