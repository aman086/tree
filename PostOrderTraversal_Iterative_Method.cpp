/*
Inorder - left/root/right
Preorder - root/left/right
Postorder - left/right/root



In this question we have to do one extra step ....
    first we find traversal in this way -> (root/right/left) and made an array
    then reverse the array and we got our final post order Traversal


                        1

                     /     \

                   2         3

                 /    \     /  

              4         5  6

                              \

                                 7

                                   \

                                     8
     PostOrderTraversal - (4,5,2,8,7,6,3,1)
     first we find traversal in this way -> (root/right/left) so at that
      point array - (1,3,6,7,8,2,5,4) which is reverse of original PostOrder Traversal
      so we reverse it to get to our final answer.                                
  

*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
   Node* left;
   Node* right;
   int data;
   Node(int vl){
    data = vl;
    left = NULL;
    right = NULL;  
   }
};


void PostOrder(struct Node* &root){
   if(root==NULL) return;
   vector<int> finalList;
   stack<Node*> st;
   st.push(root);
   while(!st.empty()){
         Node* node = st.top();
         st.pop();
         finalList.push_back(node->data);
         if(node->left!=NULL) st.push(node->left);
         if(node->right!=NULL) st.push(node->right);
   }
   reverse(finalList.begin() , finalList.end());
   for(auto vl : finalList)
         cout<<vl<<" ";
      cout<<endl;
}

int main(){
   struct Node* root = new  Node(1);
   root->left = new  Node(2);
   root->right = new  Node(3);
   root->left->left = new  Node(4);
   root->left->right = new  Node(5);
   root->right->left = new  Node(6);
   root->right->left->right = new  Node(7);
   root->right->left->right->right = new  Node(8);

   PostOrder(root);
}