//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   vector<string> CamelCase(int N, vector<string> Dict, string Pat) {
        int m=Pat.length();
        vector<string>ans;
        for(int i=0;i<N;i++){
            int j=0;
            int n=Dict[i].length();
            for(int k=0;k<n;k++){
                if(Dict[i][k]>='A'&&Dict[i][k]<='Z'){
                    if(Pat[j]==Dict[i][k]){
                        if(j==m-1){
                            ans.push_back(Dict[i]);
                            break;
                        }
                        j++;
                    }
                    else break;
                }
            }
        }
        if(ans.size()==0){
            ans.push_back("-1");
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends