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
Node* bulidTREE(){
    cout<<"Enter data:"<<endl;
    int data;
    cin>>data; 
    if(data==-1)
    {
        return NULL;
    }
    Node*root= new Node(data);
    cout<<"enter at "<< data <<" left"<<endl;
     root->left=bulidTREE();
    cout<<"Enter at " <<data<<" right"<<endl;
     root->right=bulidTREE();
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
    Node*root= bulidTREE();
    cout<<"Level Order traversal :"<<endl;
    bfs(root);

}