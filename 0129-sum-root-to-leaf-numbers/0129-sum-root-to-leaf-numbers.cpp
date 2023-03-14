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
    int res = 0;
    void fn(TreeNode* root,int curr){
        if(root==NULL)return ;
        if(root->left==NULL && root->right==NULL){
            res += (curr*10+root->val);return;
        }
        fn(root->left,curr*10+root->val);
        fn(root->right,curr*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        fn(root,0);
        return res;
    }
};