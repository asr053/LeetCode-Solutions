class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i])continue;
            bool check = 1;
            
            if(i-1>=0 && flowerbed[i-1]==1)check=0;
            if(i+1<flowerbed.size() && flowerbed[i+1]==1)check=0;
          
            if(check)res++,flowerbed[i]=1;
        }
        return res>=n;
    }
};