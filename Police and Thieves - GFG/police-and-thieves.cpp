//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        queue<int>t,p;
        int res = 0;
        for(int i=0;i<n;i++){
            if(t.size() && i-t.front()>k)t.pop();
            if(p.size() && i-p.front()>k)p.pop();
            if(arr[i]=='P'){
                if(t.size())t.pop(),res++;
                else p.push(i);
            }else if(arr[i]=='T'){
                if(p.size())p.pop(),res++;
                else t.push(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends