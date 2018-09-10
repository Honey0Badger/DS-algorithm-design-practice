/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        string tr;
        if (!root) return tr;
        string lt = serialize(root->left);
        string rt = serialize(root->right);
        if (!lt.empty()) tr = lt+",";
        tr += to_string(root->val);
        if (!rt.empty()) tr += ",[," + rt +",]";
        return tr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return read_recursive(data, i);
    }
    
    TreeNode* read_recursive(string& data, int& i) {
        TreeNode* pt=NULL;        
        while (i<data.length()) {
            string dat = read_dat(data, i);
            if (dat.compare("[") == 0) pt->right = read_recursive(data, i);
            else if (dat.compare("]") == 0) return pt;
            else {
                TreeNode* pnew = new TreeNode(stoi(dat));
                pnew->left = pt;
                pt = pnew;
            }
        }
        return pt;        
    }    
    
    string read_dat(const string& data, int& i) {
        int p=i;
        while (p<data.length() && data[p] != ',') ++p;
        string ans=data.substr(i, p-i);
        i = p+1;
        return ans;
    }   
};