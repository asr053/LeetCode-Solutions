class Solution {
public:
    int numDecodings(string s) {
        int last = 0 , second_last = 1;
        if(s[0]!='0')last = 1;
        else return 0;
        
        for(int i=1;i<s.size();i++){
            int curr = 0;
            if(s[i]!='0'){
                curr=last;
            }
            if((s[i-1]=='1' && s[i]<='9') ||(s[i-1]=='2' && s[i]<='6'))curr += second_last;
            second_last = last;
            last = curr;
        }
        return last;
    }
};