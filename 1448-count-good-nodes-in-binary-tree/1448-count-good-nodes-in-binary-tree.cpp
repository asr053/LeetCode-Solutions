/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    void fn(TreeNode* root,int mx){
        if(root==NULL)return ;
     
        if(root->val>=mx)cnt++;
        mx = max(mx,root->val);
         (fn(root->left,mx));
        fn(root->right,mx);
        
    }
    int goodNodes(TreeNode* root) {
         fn(root,INT_MIN);
        return cnt;
    }
};