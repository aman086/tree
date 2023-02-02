#include<bits/stdc++.h>
using namespace std;

struct Node
{
   Node* left;
   Node* right;
   int data;
   Node(int data){
      this->data = data;
      left = NULL;
      right = NULL;
   }
};




bool pathRootToNode(Node* root , vector<int>& ans , Node*& ansNode){
   if(root==NULL)
      return false;
   
   if(root->left!=NULL){
      ans.push_back(root->data);
      if(root->left==ansNode){
         ans.push_back(root->left->data);
         return true;
      }
      if(pathRootToNode(root->left , ans , ansNode))
         return true;
      ans.pop_back();  
   }  
   if(root->right!=NULL){
      ans.push_back(root->data);
      if(root->right==ansNode){
         ans.push_back(root->right->data);
         return true;
      }
      if(pathRootToNode(root->right , ans , ansNode))
         return true;
      ans.pop_back();  
   }  
   return false;  

}


int main(){ 

   Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(8);
    root->right->right->left->left = new Node(9);
    root->right->right->left->left->left = new Node(10);
    vector<int> ans;
    Node* ansNode = root->right->right->left->left->left;
    // ans.push_back(root->data);
   if(pathRootToNode(root , ans , ansNode))
      cout<<"Path Exist"<<endl;
   else
      cout<<"Path doesn't exist"<<endl;
   for(auto it : ans)
      cout<<it<<" ";
   cout<<endl;

}
