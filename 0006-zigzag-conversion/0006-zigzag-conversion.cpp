class Solution {
public:
    string convert(string s, int r) {
         if(r==1)return s;
         string res = "";
        int val = r+r-2;
        int left = val , right = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='0')continue;
           
            if(i==0 || i==r-1){
                int j = i;
            while(j<s.size()){
                res += s[j];
                s[j]='0';
                j+=val;
                //cout<<val<<endl;
            } 
            }else{
                bool check = 1;
                int j = i;
                while(j<s.size()){
                    res+=s[j];
                    s[j]='0';
                    if(check){j+= left;check=0;}
                    else {j+=right;check=1;}
                }
            }     
        
             left -=2 , right +=2;
        }
        return res;
    }
};