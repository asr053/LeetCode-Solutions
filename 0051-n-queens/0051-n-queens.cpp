class Solution {
public:
   vector<vector<string>>res;
   bool isValid(vector<string>&curr,int row,int col,int n){
       for(int i=0;i<n;i++){
           if(i!=row && curr[i][col]=='Q')return false;
       }
       for(int j=0;j<n;j++){
           if(j!=col && curr[row][j]=='Q')return false;
       }
       int i = row , j = col;
       while(i>=0 && j>=0){
           if(curr[i][j]=='Q')return false;
           i--;j--;
       }
       i=row,j=col;
       while(i<n && j<n){
        if(curr[i][j]=='Q')return false;
        i++;j++;
       }
       i=row,j=col;
       while(i<n && j>=0){
           if(curr[i][j]=='Q')return false;
           i++;j--;
       }
       i=row,j=col;
       while(i>=0 && j<n){
           if(curr[i][j]=='Q')return false;
           i--;j++;
       }
       return true;
   }
   void fn(int row,vector<string>curr,int n){
       if(row==n){
         res.push_back(curr);return ;
       }
       for(int j=0;j<n;j++){
           if(isValid(curr,row,j,n)){
               curr[row][j]='Q';
               fn(row+1,curr,n);
               curr[row][j]='.';
           }
       }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>curr(n,string(n,'.'));
        fn(0,curr,n);
        return res;
    }
};