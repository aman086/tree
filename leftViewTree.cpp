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




void rightViewTree(Node*& root){
   if(root==NULL)
      return;

   queue<pair<Node* , int>> qu;
   map<int , int> mp;
   qu.push({root , 0});
   while(!qu.empty()){
      auto queObj = qu.front();
      qu.pop();
      Node* node = queObj.first;
      int level = queObj.second;
      if(mp.find(level)==mp.end())
      mp[level] = node->data;
      if(node->left!=NULL)
         qu.push({node->left , level+1});
      if(node->right!=NULL)
         qu.push({node->right , level+1});

   }
   vector<int> ans;
   for(auto it : mp)
      ans.push_back(it.second);
   for(auto iter : ans)
      cout<<iter<<" ";
   cout<<endl;
}


int main(){ 

   Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
   rightViewTree(root);

}