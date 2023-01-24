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


void levelOrder(struct Node* &root){
   if(root==NULL)
      return;
   vector<vector<int>> finalList;
   queue<Node*> qu;
   qu.push(root);
   while(!qu.empty()){
       int size = qu.size();
       vector<int> current;
       for(int i=0;i<size;i++){
         Node* node = qu.front();
         current.push_back(node->data);
         qu.pop();
         if(node->left!=NULL) {qu.push(node->left);}
         if(node->right!=NULL) {qu.push(node->right);}
       }
       finalList.push_back(current);
   }
   for(auto it : finalList){
      for(auto vl : it)
         cout<<vl<<" ";
      cout<<endl;
   }
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

   levelOrder(root);
}