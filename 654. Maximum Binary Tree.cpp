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
// distance(A, max_element(A, A + N))
  void constructTree(TreeNode*& root  , vector<int>& nums , int start , int end){
        if(start==end){
            TreeNode* curr = new TreeNode(nums[start]);
            root = curr;
            return;
        }
        
        int ind = distance(nums.begin() , max_element(nums.begin()+start , nums.begin()+end));
        TreeNode* curr = new TreeNode(nums[ind]);
        root = curr;
        if(ind>start)
        constructTree(root->left , nums , start , ind);
        if(ind<(end-1))
        constructTree(root->right , nums , ind+1 , end);
        
  }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int ind = distance(nums.begin() , max_element(nums.begin() , nums.end()));
        TreeNode* root = new TreeNode(nums[ind]);
        if(ind>0)
        constructTree(root->left , nums , 0 , ind);
        if(ind<(nums.size()-1))
        constructTree(root->right , nums , ind+1 , nums.size());
        return root;
    }
};
