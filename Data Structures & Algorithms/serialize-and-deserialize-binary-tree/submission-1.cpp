
class Codec {
public:
    int data(string &s, int &idx) {
        int val = 0;
        while (s[idx] != '#') {
            int l = s[idx] - '0';
            val = (val * 10) + l;
            idx++;
        }
        idx++;
        
        return val;
    }

    TreeNode* helper(string &s, int &idx) {
        if (s[idx] == 'n') {
             idx++;
             return NULL;}

        TreeNode* root = new TreeNode(data(s, idx));
        root->left = helper(s, idx);
        root->right = helper(s, idx);
        return root;
    }

    string serialize(TreeNode* root) {
        if (root == NULL) return "n";

        string s = "";
        s += to_string(root->val);
        s += '#';
        s += serialize(root->left);
        s += serialize(root->right);
        return s;
    }

    TreeNode* deserialize(string data) {

        int idx = 0;
        return helper(data, idx);
    }
};
