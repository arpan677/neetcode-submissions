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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;

        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode *prev=NULL;

        

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();


            if (node == NULL) {
                
               ans.push_back(prev->val);

                if (!q.empty()) {
                    q.push(NULL);
                }
            } 
            
            else {
             

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
               
            }
             prev=node;
        }

        return ans;
    }
};
