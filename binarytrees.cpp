#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* right;
        node* left;
    node(int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node* create(node* root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;
    cout<<"Enter the data for inserting in left of "<<data<<": "<<endl;
    root->left=create(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<": "<<endl;
    root->right=create(root->right);

    return root;

}

void traversal(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp = q.front();
 
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

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void levelorder(node* &root) {
    queue<node*> q;
    int x;
    cout << "Enter the data for the root: ";
    cin >> x;
    root = new node(x);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the data for the left node of " << temp->data << " : ";
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the data for the right node of " << temp->data << " : ";
        cin >> rightData;
        
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}



int main() {
    node* root = NULL;

    levelorder(root);
    traversal(root);
/*
    root = create(root);
   cout<<"Here's the bt"<<endl;
   //traversal(root);
   //cout<<endl;
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1
    cout<<"Here's the inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Here's the preorder traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Here's the postorder traversal: ";
    postorder(root);
    cout<<endl;

    */

    return 0;
    

}