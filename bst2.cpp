#include<iostream>
using namespace std;
#include<queue>
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};
Node*build_BST(Node*&root,int data)
{
       if(root==NULL)
       {
        root = new Node(data);
        return root;
       }
       if(root->data>data)
       {
           root->left=build_BST(root->left,data);
       }
       else{
        root->right=build_BST(root->right,data);
       }
       return root;
}
void insert_Data(Node*&root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
       root= build_BST(root,data);
       cin>>data;
    }
}
void BFS(Node*root)
{
   queue<Node*>q;
   if(root)
   {
    q.push(root);
   }
   while(!q.empty())
   {

    int n = q.size();
    while(n--)
    {
        Node* top= q.front();
        q.pop();
        cout<<top->data<<" ";
        if(top->left)
        {
            q.push(top->left);
        }
        if(top->right)
        {
            q.push(top->right);
        }
    }
    cout<<endl;
   }
}

int main()
{
     Node*root=NULL;
     insert_Data(root);
     cout<<"BFS: "<<endl;
     BFS(root);
}