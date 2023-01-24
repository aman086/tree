#include<bits/stdc++.h>
using namespace std;

struct Node
{
   Node* left;
   Node* right;
   int data;
   int cnt;
   Node(int data){
      this->data = data;
      cnt = 0;
      left = NULL;
      right = NULL;
   }
};


// LevelOrderSolution....



/*
void levelOrder(Node* &root){
   if(root==NULL) return;
   queue<Node*> qu;
   qu.push(root);
   vector<vector<int>> finalAnswer;
   int count=0;
   while(!qu.empty()){
      vector<int> currAnswer;
      int size = qu.size();
      count++;
      for(int i=0;i<size;i++){
       Node* node = qu.front();
       currAnswer.push_back(node->data);
       qu.pop();
       if(node->left!=NULL) qu.push(node->left);
       if(node->right!=NULL) qu.push(node->right);
      }
      finalAnswer.push_back(currAnswer);
   }
   cout<<count<<endl;
   for(auto it : finalAnswer){
      for(auto vl : it)
         cout<<vl<<" ";
   cout<<endl;
   }
 }
*/



// Recursive solution....

/*
method (01)->

 here we found our solution by starting from root 
   and left child = parent + 1 (if not null)
   right child = parent + 1  (if not null)

   and then these child became parents and again
      left = parent + 1 (if not null)
      right = parent + 1 (if not null)

      and we have to maintain a global variable for keeping a track on maximum
      height...

      and we can do this without a global variable which is discussed below in 
      method (2) of recurive solution 
*/
/*
int maxi = INT_MIN;

void recursiveSolution(Node* &root , int count){
   root->cnt = count;
   if(root->left!=NULL){
      maxi = max(maxi , count+1);
    recursiveSolution(root->left , count+1);
  }
   if(root->right!=NULL){
      maxi = max(maxi , count+1);
    recursiveSolution(root->right , count+1);
  }
}
*/

/*
Method (02):
       
       here we follow a concept:

               parent = 1 + max(left height , right height);
               jb kisi ka left ya right child null hota hai tb hm 0 return kr dete hai
               aur us leaf node ki height 1 ho jati hai.
               aur similar fashion me parents v update hoge..

*/


int  recursiveSolution_(Node* &root){
   if(root==NULL)
      return 0;
   return 1 + max(recursiveSolution_(root->left) , recursiveSolution_(root->right));
}



int main(){
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
     root->left->right = new Node(6);
   root->right->right = new Node(7);
   root->right->right->left = new Node(8);
   // levelOrder(root);
   // recursiveSolution(root , 1);
   cout<<recursiveSolution_(root);
   // cout<<maxi<<endl;
}