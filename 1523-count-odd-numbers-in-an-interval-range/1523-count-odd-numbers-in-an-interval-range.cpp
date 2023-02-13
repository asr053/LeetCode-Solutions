class Solution {
public:
    int countOdds(int low, int high) {
        int cnt = 0;
        if(low%2){cnt++;low++;}
        if(high%2){cnt++;high--;}
        return (cnt+(high-low)/2);
    }
};