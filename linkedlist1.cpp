#include<iostream>

using namespace std;


class Node{
    public: 
        int data;
        Node*next;

    Node(int value){
        this-> data=value;
        this->next=NULL;
    }

   ~Node(){
        int value=this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"The memory holding the value: "<<value<<" has been freed!"<<endl;
    } 
   /*   ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    } */
};

void InsertNode(Node* &head, int dat){
    Node* temp= new Node(dat);
    temp->next=head;
    head=temp;
}

void TraversLL(Node * &head){
    Node *temp;
    temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

void insertend(Node* &head, int dat) {
    Node* new_node = new Node(dat);
    Node* temp = head;

    if (head == nullptr) {
        // If the linked list is empty, make the new node the head.
        head = new_node;
    } else {
        // Traverse the linked list to find the last node.
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end.
        temp->next = new_node;
    }

    TraversLL(head);
}
void insertMiddle(Node* &head, int position, int d){
    Node* ptr= new Node(d);

    Node *temp=head;
    int i=0;

    while(i<position-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next= ptr;
}

void del(int position, Node* & head) { 

    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}



int main(){

    Node* node1= new Node(10);
    /*cout<< node1->data<<endl;
    cout<< node1->next<<endl;*/

   Node*head=node1;
    TraversLL(head);

    InsertNode(head,20);

    TraversLL(head);

    InsertNode(head,15);

    TraversLL(head);

    insertend(head,5);
 
    insertMiddle(head,2,77);

    TraversLL(head);

    del(2,head);

    TraversLL(head);

    return 0;

}