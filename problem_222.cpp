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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if (leftheight > rightheight) {
            return (1 << rightheight) + countNodes(root->left);
        } else {
            return (1 << leftheight) + countNodes(root->right);
        }
    }
    
    int height(TreeNode* node) {
        int h = 0;
        while (node) {
            node = node->left;
            h++;
        }
        return h;
    }
    
};