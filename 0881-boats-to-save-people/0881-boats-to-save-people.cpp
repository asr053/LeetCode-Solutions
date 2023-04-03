class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int total = 0;
        int l = 0 , h = people.size()-1;
        while(l<=h){
            if(l==h){total++,l++,h--;continue;}
            if(people[l]+people[h]>limit)h--,total++;
            else l++,h--,total++;
        }
        return total;
    }
};