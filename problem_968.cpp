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
    int camera = 0;
public:
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* fakeRoot = new TreeNode(0);
        fakeRoot->left = root;
        minCameraCover_help(fakeRoot);
        return camera;
    }
    
    bool minCameraCover_help(TreeNode* node) {
        if (node == nullptr) return true;
        if (node->left == nullptr && node->right == nullptr) { // leaf
            return false;
        }
        bool left = minCameraCover_help(node->left);
        bool right = minCameraCover_help(node->right);
        if (!left || !right) {
            node->val = 1;
            camera +=1;
        }
        
        if (node->left != nullptr && node->left->val == 1 ||
           node->right != nullptr && node->right->val == 1 ||
           node->val == 1) return true;
        else return false;
    }
};