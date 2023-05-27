class Solution {
public:
int dp[50002][2];
    int f(int turn , int ind,int total , vector<int>&v){
         if(ind>=v.size()){return total;}
          if(turn ==0 && dp[ind][turn]!=INT_MIN)return dp[ind][turn];
         if(turn ==1 && dp[ind][turn]!=INT_MAX)return dp[ind][turn];
         if(turn==0){
             int first = INT_MIN, second = INT_MIN, third = INT_MIN;
             if(ind<v.size())first = f(1,ind+1,total,v)+v[ind];
             if(ind+1<v.size())second = f(1,ind+2,total,v)+v[ind]+v[ind+1];
             if(ind+2<v.size())third = f(1,ind+3,total,v)+v[ind]+v[ind+1]+v[ind+2];
             return dp[ind][turn]=max({first,second,third});
         }else{
              int first = INT_MAX , second =INT_MAX  , third = INT_MAX ;
             if(ind<v.size())first = f(0,ind+1,total,v)-v[ind];
             if(ind+1<v.size())second = f(0,ind+2,total,v)-v[ind]-v[ind+1];
             if(ind+2<v.size())third = f(0,ind+3,total,v)-v[ind]-v[ind+1]-v[ind+2];
             return dp[ind][turn]=min({first,second,third});
         }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int turn = 0 , ind = 0 , total = 0 ;
         for(int i=0;i<50002;i++)dp[i][0]=INT_MIN;
         for(int i=0;i<50002;i++)dp[i][1]=INT_MAX;
       int res = f(turn,ind,total,stoneValue);

       if(res>0)return "Alice";
       else if(res<0)return "Bob";
       else return "Tie";
    }
};