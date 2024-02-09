#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
        this->data = d;
        this->right=NULL;
        this->left=NULL;
    }
};

Node* insert(Node* &root, int d){
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    else if(root->data>d){
        root->left= insert(root->left,d);
    }
    else{
        root->right=insert(root->right,d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        insert(root,data);
        cin>>data;

    }

}

void traversal(Node* &root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();
 
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
                   cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
    }
}

void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main() {

    Node* root=NULL;
    cout<<"Enter data into the BST: "<<endl;
    takeInput(root);

    cout<<"Here's the BST: "<<endl;

    inorder(root);


    return 0;
}
