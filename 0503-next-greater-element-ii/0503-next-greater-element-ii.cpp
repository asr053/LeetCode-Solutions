class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       stack<int>st;
        int n = nums.size();
       vector<int>res(nums.size(),-1);
        for(int i=0;i<2*n;i++){
            while(st.size() && nums[st.top()%n]<nums[i%n]){
                res[st.top()%n]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};