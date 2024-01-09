#include<iostream>
#include<queue>
using namespace std;
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

Node* build_BST(Node*root,int data){
    if(root==NULL)
    {
        Node*root=new Node(data);
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
void take_input(Node*&root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
       // Node*root= new Node(data);
      root=  build_BST(root,data);
        cin>>data;
    }
}
void bfs(Node*&BSTree)
{
     queue<Node*>q;
     q.push(BSTree);
     while(!q.empty())
     {
        int n= q.size();
        while(n--)
        {
            Node* top = q.front();
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
    cout<<"Enter data : "<<endl;
    Node* root=NULL;
take_input(root);
cout<<endl<<"  "<<" Printing levelorder :"<<endl;
    bfs(root);

    return 0;
}