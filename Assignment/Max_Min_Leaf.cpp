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

void mx_val(Node* root,int & mx)
{
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL) mx=max(mx,root->val);
    mx_val(root->left,mx);
    mx_val(root->right,mx);
   
}
void mn_val(Node* root,int & mn)
{
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL) mn=min(mn,root->val);
    mn_val(root->left,mn);
    mn_val(root->right,mn);
   
}
int main()
{
    Node* root= input_tree();
    int mx=INT_MIN;
    int mn=INT_MAX;
    mx_val(root,mx);
    mn_val(root,mn);
    cout<<mx<<" "<<mn<<endl;

    return 0;
}