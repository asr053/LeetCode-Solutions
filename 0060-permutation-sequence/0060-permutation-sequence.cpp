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
        set<int>unused , used;
        for(int i=1;i<=n;i++)unused.insert(i);
        int total = 0;
        string res = "";
        for(int i=1;i<=n;i++){
            set<int>temp;
            while(fn(n-i)+total<k){
                auto it = unused.begin();
                temp.insert(*(it));
                unused.erase(*(it));
                total += fn(n-i);
            }
            auto it = unused.begin();
            res +=( (*it)+'0');
            for(auto it:temp)unused.insert(it);
            used.insert(*(it)); unused.erase(*(it));
        }
        return res;
    }
};