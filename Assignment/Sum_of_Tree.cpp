#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* input_tree()
{
    int val;
    cin>>val;
    Node* root;
    if(val==-1) root=NULL;
    else root = new Node(val);
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty())
    {
        //1 ber kore ana;
        Node* p = q.front();
        q.pop();
        //2 jabotio kaj  kora;
        int l,r;
        cin>>l>>r;
        Node* myLeft;
        Node* myright;
        if(l==-1) myLeft = NULL;
        else myLeft= new Node(l);
        if(r==-1) myright=NULL;
        else myright= new Node(r);
        p->left=myLeft;
        p->right=myright;
        //3 tar children gulo ke raka;
        if(p->left) q.push(p->left);
        if(p->right)q.push(p->right);


    }
    return root;

}
int sumOfVal(Node* root)
{
    if(root==NULL) return 0;
    int sum =root->val+sumOfVal(root->left)+sumOfVal(root->right);
    return sum;
}
// void level_order(Node* root)
// {
//     if(root==NULL) return;
//     queue<Node*>q;
//     q.push(root);
//     while (!q.empty())
//     {
//         //1. ber kore ana;
//         Node* f= q.front();
//         q.pop();
//         //2. jabotio kaj kora;
       
//         //tar children gulo ke raka.
//         if(f->left)q.push(f->left);
//         if(f->right)q.push(f->right);
        
//     }
    
// }
int main()
{
    Node* root= input_tree();
    // level_order(root);
     cout<<sumOfVal(root)<<" ";

    return 0;
}