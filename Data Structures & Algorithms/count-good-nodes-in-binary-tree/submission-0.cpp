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

    int helper(TreeNode *root,int val){
        if(!root) return 0;


        int left=helper(root->left,max(val,root->val));
        int right=helper(root->right,max(val,root->val));

          return left+right+(root->val>=val);
    }

    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
        
        
    }
};
