class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(c || a || b){
            if(c%2){
                if(a%2==0 && b%2==0) cnt++;
            }else{
                if(a%2 && b%2)cnt+=2;
                else if(a%2 || b%2)cnt++;
            }
            a/=2;b/=2;c/=2;
        }
        return cnt;
    }
};