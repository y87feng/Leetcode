/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* newnode = new TreeNode(val);
        if (root == nullptr) return newnode;
        while (cur != nullptr) {
            if (cur->val < val) {
                if (cur->right == nullptr) {
                    cur->right = newnode;
                    break;
                } else {
                    cur = cur->right;
                }
            }
            if (cur->val > val) {
                if (cur->left == nullptr) {
                    cur->left = newnode;
                    break;
                } else {
                    cur = cur->left;
                }
            }
        }
        
        return root;
    }
};