class Solution {
public:
     int fn(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}
    string getPermutation(int n, int k) {
        vector<int> unused(n+1,1),used(n+1,0);
     
        int total = 0;
        string res = "";
        for(int i=1;i<=n;i++){
            int p = 1;
            while(unused[p]!=1)p++;
            while(fn(n-i)+total<k){
                p++;
                 while(unused[p]!=1)p++;
                total += fn(n-i);
            }
            //cout<<p<<endl;
            unused[p]=0;used[p]=1;
            res += (p+'0');
        }
        return res;
    }
};