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
    void longestUnivaluePath(TreeNode* root , long long int sum , long long int& finalSum) {
    sum = sum*10 + root->val;

    if(root->left!=NULL){
       longestUnivaluePath(root->left , sum , finalSum);
    }

    if(root->right!=NULL)
      longestUnivaluePath(root->right , sum , finalSum);

   if(root->left==NULL && root->right==NULL){
      finalSum += sum;
   }
}
    int sumNumbers(TreeNode* root) {
        long long int sum = 0;
   long long int finalSum = 0;
   longestUnivaluePath(root , sum , finalSum);
   return (int)finalSum;
    }
};
