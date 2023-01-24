/*
Inorder - left/root/right
Preorder - root/left/right
Postorder - left/right/root
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
   struct Node* left;
   struct Node* right;
   int data;
   Node(int vl){
    data = vl;
    left = NULL;
    right = NULL;  
   }
};


void PreOrder(struct Node* &root){
   if(root==NULL)
      return;
   cout<<root->data<<" ";
   PreOrder(root->left);
   PreOrder(root->right);
}

int main(){
   struct Node* root = new  Node(1);
   root->left = new  Node(2);
   root->right = new  Node(3);
   root->left->left = new  Node(4);
   root->left->right = new  Node(5);

   PreOrder(root);
}