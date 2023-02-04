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
    void solve(TreeNode*& root, int value){
       if(root->right==NULL){
            TreeNode* curr = new TreeNode(value);
            root->right = curr;
            return;
        }
        if(value > (root->right->val)){
            TreeNode* curr = new TreeNode(value);
            curr->left = root->right;
            root->right = curr;
            return;
        }

        return solve(root->right , value);

    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int value) {
        if(root == NULL) return NULL;

        if(value > root->val){
            TreeNode* curr = new TreeNode(value);
            curr->left = root;
            return curr;
        }
        // if(root->right)
        solve(root , value);
        return root;
    }
};
