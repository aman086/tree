/*
Inorder - left/root/right
Preorder - root/left/right
Postorder - left/right/root
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


void PreOrder(struct Node* &root){
   if(root==NULL) return;
   vector<int> finalList;
   stack<Node*> st;
   st.push(root);
   while(!st.empty()){
         Node* node = st.top();
         finalList.push_back(node->data);
         st.pop();
         if(node->right!=NULL) st.push(node->right);
         if(node->left!=NULL) st.push(node->left);
   }
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
   root->left->right->left = new  Node(15);
   root->left->right->right = new  Node(25);
   root->left->left->left = new  Node(6);
   root->left->left->right = new  Node(7);

   PreOrder(root);
}