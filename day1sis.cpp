#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->data=data;
        Node*left=NULL;
        Node*right=NULL;
    }

};
Node* bulidTREE(){
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data; 
    if(data==-1)
    {
        return NULL;
    }
    Node*root= new Node(data);
    cout<<"enter at root's left"<<endl;
     root->left=bulidTREE();
    cout<<"Enter at root's right"<<endl;
     root->right=bulidTREE();
     return root;
    

}
void preorder(Node*root)
{
    if(!root)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void inorder(Node*root)
{
    if(!root)
    {
        return ;
    }
   
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(Node*root){
    if(!root)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
  Node* root= bulidTREE();
  cout<<"Preorder :"<<endl;
  preorder(root);
  cout<<endl;
  cout<<"InOrder :"<<endl;
  inorder(root);
  cout<<endl;
  cout<<" Post order :"<<endl;
  postorder(root);

}