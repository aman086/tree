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


    
void hasPathSum(TreeNode* root, int  targetSum , long long int& currSum , vector<int>& currResult ,int& count) {
     
       
       currSum+=root->val;
        currResult.push_back(root->val);

       if(currSum == targetSum){
           count++;
        //   finalResult.push_back(currResult);
       }

          long long int vl = currSum;
          int k=0;
          int size = currResult.size();
          while(k<size){
            vl -= currResult[k];
            k++;
               if(vl == targetSum){
                  vector<int> v1(currResult.begin()+k , currResult.end());
                  if(v1.size()!=0)
                   count++;
                //   finalResult.push_back(v1);
               }
          }
    //    }


       if(root->left!=NULL){
            hasPathSum(root->left , targetSum , currSum , currResult , count);
       }

       if(root->right!=NULL){
            hasPathSum(root->right , targetSum , currSum , currResult , count);
       }

       currSum-=root->val;
       currResult.pop_back();

}


    int pathSum(TreeNode* root, int targetSum) {
        vector<int> currResult;
        if(root==NULL) return 0;
        long long int currSum = 0;
        int count=0;
        hasPathSum(root , targetSum , currSum ,  currResult , count);
        return count;
    }
};
