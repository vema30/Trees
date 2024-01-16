#include<iostream>
using namespace std;
#include<bits/stdc++.h>
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
void build_map (Node*root,unordered_map<int,list<int>>&list)
{
       if(!root)
       {
        return;
       }
       if(root->left)
       {
        list[root->data].push_back(root->left->data);
        list[root->left->data].push_back(root->data);
       }
       if(root->right)
       {
        list[root->data].push_back(root->right->data);
        list[root->right->data].push_back(root->data);
       }
       build_map(root->left,list);
       build_map(root->right,list);
}

int burn_Tree(int infected_node, unordered_map<int,list<int>>&list)
{
    queue<int>q;
    q.push(infected_node);
    int time=-1;
    unordered_set<int>set;
    while(!q.empty())
    {
        time++;
        int n = q.size();
        while(n--)
        {
            int node= q.front();
            q.pop();
            set.insert(node);
            for(int neibour:list[node])
            {
                if(set.find(neibour)==set.end())
                {
                    q.push(neibour);
                }
            }
        }
    }
    return time;
}
int main()
{
    Node*root= bulidTREE();
    unordered_map<int,list<int>>list;
    build_map(root,list);
    for(auto it:list)
    {
        cout<<it.first<<" : "<<"{  ";
       for(auto i:it.second)
       {
        cout<<i<<" ";
       }
       cout<<'}'<<endl;
    }
    int infected_node=3;
    cout<<endl<<'\n'<<endl<<"MINIMUM TIME IS :"<<;
    cout<<burn_Tree(infected_node,list);



}