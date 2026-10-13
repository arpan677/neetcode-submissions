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
    int ans = -1;
    int k=0;
    void helper(TreeNode* root, int c) {
      if(root==NULL) return ;
      helper(root->left,c);
      k++;
      if(k==c) ans=root->val;
      helper(root->right,c);

    }

    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans;
    }
};
