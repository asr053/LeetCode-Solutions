class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)x=(1/x);
        double ans = 1 , curr = x;
        while(n){
            if(n%2)ans *= curr;
            n/=2;
            curr *= curr;
            //cout<<curr<<endl;
        }
        return ans;
    }
};