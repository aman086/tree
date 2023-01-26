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

    int longestUnivaluePath_(TreeNode* root , int& final){
           if(root==NULL) return 0;
   int leftHeight = 0,rightHeight = 0;
   if(root->left!=NULL){
      leftHeight = longestUnivaluePath_(root->left , final);
      if(root->val != root->left->val)
         leftHeight = 0;
   }  

   if(root->right!=NULL){
         rightHeight = longestUnivaluePath_(root->right , final);
      if(root->val != root->right->val)
         rightHeight =   0;
   } 

   final = max(final , leftHeight + rightHeight+1);
   return max(leftHeight , rightHeight) + 1;
}
    int longestUnivaluePath(TreeNode* root) {
       int final = 0;
       if(root==NULL) return 0;
       longestUnivaluePath_(root , final);
       return final-1;
    }
};
