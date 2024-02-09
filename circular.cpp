#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int dat){
        this->data=dat;
        this->next=NULL;
    }
    ~Node(){
        int value= this->data;
        if (this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"The node containing the element "<<value<<"has been deleted"<<endl;
    }

};


void create(Node* &head, int dat){
  Node* node1=new Node(dat);
  if (head==NULL)
    cout<<"Underflow!"<<endl;
    else{
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;

            node1->next=temp->next;
            temp->next=node1;

    }
}

void traverse(Node* &head){
    Node* temp=head;

    if (head==NULL){
        cout<<"List is empty!"<<endl;
    }

    else{

        do {
        cout<<temp->data<<"-->";
        temp= temp->next;
        } while (temp!=head);
    }
}

int main(){
    Node* n1= new Node(1);
    Node* head= n1;

    create(head,2);
    traverse(head);

 return 0;
}