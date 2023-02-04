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

    void zigZagTraversal(TreeNode* root , vector<vector<int>>& finalAns){
        queue<TreeNode*> qu;
        qu.push(root);
        bool leftToRight = true;
        while(!qu.empty()){
            int size = qu.size();
            vector<int> curr(size);
            for(int i=0;i<size;i++){
                TreeNode* node = qu.front();
                qu.pop();
                if(leftToRight)
                curr[i] = node->val;
                else
                curr[size-i-1] = node->val;
                if(node->left!=NULL) qu.push(node->left) ;
                if(node->right!=NULL) qu.push(node->right) ;
            }
            leftToRight = !leftToRight;
            finalAns.push_back(curr);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return{};
        vector<vector<int>> finalAns;
            zigZagTraversal(root , finalAns);
        return finalAns;
    }
};
