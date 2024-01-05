#include<iostream>
using namespace std;
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
        Node*left=NULL;
        Node*right=NULL;
    }

};
int find_idx(int inorder[],int ele,int n)
{
    for(int i =0;i<n;i++)
    {
        if(inorder[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
Node* preorder_inoder_Build_Tree(int preorder[],int inorder[],int left, int right,int &preindex,int size)
{
         if(left>right)
         {
            return nullptr;
         }
         Node* root= new Node(preorder[preindex++]);
         int idx=find_idx(inorder,root->data,size);
         root->left=preorder_inoder_Build_Tree(preorder,inorder,left,idx-1,preindex,size);
         root->right=preorder_inoder_Build_Tree(preorder,inorder,idx+1,right,preindex,size);
         return root;

}
void bfs(Node*&root)
{
    if(!root)
    {
        cout<<"Tree is empty";
        return ;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int len = q.size();
        while(len--)
        {
            Node*temp = q.front();
            q.pop();
            if(temp)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
     
}
int main()
{
    int preorder[5]={3,9,20,15,7};
    int inorder[5]={9,3,15,20,7};

int preindex=0;
    Node* root = preorder_inoder_Build_Tree(preorder,inorder,0,4,preindex,5);
    bfs(root);

}