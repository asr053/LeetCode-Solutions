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
    
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>q;
        q.push(root);
        bool check = 0;
        while(q.size()){
            queue<TreeNode*> temp;
            bool c = 0;
            while(q.size()){
                TreeNode* node = q.front();q.pop();
                
                if(node->left==NULL && node->right==NULL){check=1;continue;}
                
                if(node->left!=NULL){if(check)return false;temp.push(node->left);}
                else{
                   {check=1;}
                }
                 if(node->right!=NULL){if(check)return false;temp.push(node->right);}
                else{
                   {check=1;}
                }
                
            }
            
            while(temp.size()){q.push(temp.front());temp.pop();}
        }
        return true;
    }
};