class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>v;
        int i=-1;
        for(auto it:queries){
            i++;
            int first = it[0], second = it[1];
            if(first<second)swap(first,second);
         map<int,int>mp1;
            int total = 1;
            mp1[first]=1;
            while(first>0){
                if(first%2){first-=1;}
                first/=2;
                total++;
                mp1[first]=total;
            }
            if(mp1.count(second)){v.push_back(mp1[second]);continue;}
            first = second;
            total = 1;
            while(first>0){
                if(first%2){first-=1;}
                first/=2;
                if(mp1.count(first)){
                    v.push_back(mp1[first]+total);break;
                }
                total++;
            }
            
        }
        return v;
    }
};