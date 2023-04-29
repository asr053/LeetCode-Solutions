class Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        while(n!=1 && !st.count(n)){
             int temp = 0;
            st.insert(n);
            while(n){
                temp += ((n%10)*(n%10));
                n/=10;
            }
            n = temp;
        }
        return (n==1);
    }
};