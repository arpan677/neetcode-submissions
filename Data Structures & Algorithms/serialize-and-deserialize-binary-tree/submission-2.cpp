
class Codec {
public:
    void encode(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "n#";
            return;
        }

        s += to_string(root->val);
        s += '#';

        encode(root->left, s);
        encode(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s = "";
        encode(root, s);
        return s;
    }

    int data(const string &s, int &idx) {
        int sign = 1;
        if (s[idx] == '-') {
            sign = -1;
            idx++;
        }

        int val = 0;
        while (s[idx] != '#') {
            val = val * 10 + (s[idx] - '0');
            idx++;
        }

        idx++;
        return val * sign;
    }

    TreeNode* helper(const string &s, int &idx) {
        if (s[idx] == 'n') {
            idx += 2;
            return NULL;
        }

        TreeNode* root = new TreeNode(data(s, idx));
        root->left = helper(s, idx);
        root->right = helper(s, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return helper(data, idx);
    }
};
