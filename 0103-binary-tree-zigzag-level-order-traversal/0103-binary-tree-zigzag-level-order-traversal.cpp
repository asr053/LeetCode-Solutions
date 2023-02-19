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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        
        int check = 0;
        while(q.size()){
            vector<int>curr;
            queue<TreeNode*>temp;
            while(q.size()){
                curr.push_back(q.front()->val);
                if(q.front()->left !=NULL) temp.push(q.front()->left);
                if(q.front()->right != NULL)temp.push(q.front()->right);
                q.pop();
            }
            if(check)reverse(curr.begin(),curr.end());
            check = 1-check;
            while(temp.size()){q.push(temp.front());temp.pop();}
            res.push_back(curr);
        }
return res;
    }
};