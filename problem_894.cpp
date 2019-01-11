/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// DP, top-down
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        
        // check if number N is acceptable
        if (N%2 == 0 && N < 0) return res;
        
        // base case
        if (N == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        
        for (int i = 1; i < N; i +=2) {
            vector<TreeNode*> lefts = allPossibleFBT(i);
            vector<TreeNode*> rights = allPossibleFBT(N-1-i);
            
            // compose new trees
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    // new tree 
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};

// DP, bottom-up
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        
        // dp[k] stores all possible trees for k nodes
        vector<vector<TreeNode*>> dp(N+1, vector<TreeNode*>());
        
        // check if number N is acceptable
        if (N%2 == 0 && N < 0) return vector<TreeNode*>();
        
        
        
        // base case
        dp[1].push_back(new TreeNode(0));
        
        for (int i = 3; i <= N; i +=2) {
            for (int j = 1; j < i; j += 2) {
                
                // compose new tree
                
                for (TreeNode* left : dp[j]) {
                    for (TreeNode* right : dp[i-1-j]) {
                        TreeNode* root = new TreeNode(0);
                        TreeNode* copy_left = DeepCopy(left);
                        TreeNode* copy_right = DeepCopy(right);
                        root->left = copy_left;
                        root->right = copy_right;
                        
                        dp[i].push_back(root);
                    }
                }
            }
            
        }
        
        return dp[N];
    }
    
    TreeNode* DeepCopy(TreeNode* node) {
        if (node == nullptr) return nullptr;
        TreeNode* copy_node = new TreeNode(0);
        TreeNode* copy_left = DeepCopy(node->left);
        TreeNode* copy_right = DeepCopy(node->right);
        
        copy_node->left = copy_left;
        copy_node->right = copy_right;
        return node;
    }
};
