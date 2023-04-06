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
   vector<int>v;
   void f(TreeNode* root){
       if(root==NULL)return;

        v.push_back(root->val);
       if(root->left!=NULL)f(root->left);
       if(root->right!=NULL)f(root->right);
   }
    vector<int> preorderTraversal(TreeNode* root) {
       f(root);
       return v;
    }
};