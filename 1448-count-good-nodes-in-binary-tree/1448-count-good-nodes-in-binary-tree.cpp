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
    int fn(TreeNode* root,int mx){
        if(root==NULL)return 0;
        int res =0;
        if(root->val>=mx)res++;
        mx = max(mx,root->val);
        res += (fn(root->left,mx))+fn(root->right,mx);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return fn(root,INT_MIN);
    }
};