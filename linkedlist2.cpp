#include<iostream>

using namespace std;


class Node{
    public: 
        int data;
        Node* prev;
        Node*next;

    Node(int value){
        this-> data=value;
        this->prev=NULL;
        this->next=NULL;
    }

    ~Node() {
        int val = this->data;
        if (next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free for node with this data: "<<val<<endl;

    }

};

Node *tail= new Node(0);


void print(Node* head){

    Node* temp= head;
    while(temp!=NULL){
        cout<<"<--"<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<endl;
}

int len(Node * &head){
    int count=0;
    Node*temp=head;
        while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void InsertatHead(Node* &head, int dat){

    
    Node *ptr = new Node(dat);

        if(head==NULL)
             ptr=head;
    ptr->next= head;
    head->prev=ptr;
    head= ptr;

}

void InsertatTail(Node* &head,Node* &tail, int dat){
    Node *ptr = new Node(dat);
    Node* temp= head;

    if (head==NULL){
        head=ptr;
    } else{
        while(temp->next!=NULL)
                temp=temp->next;
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=NULL;
    tail=ptr;

    }
}

void InsertAtPosition(Node * &head, int pos, int dat){
    Node* ptr= new Node(dat);
    Node * temp= head;

    if(head==NULL)
        ptr=head;
    if (pos==1){
        InsertatHead(head, dat);
    }
    else{
        if(pos>len(head)){
            InsertatTail(head,tail,dat);
        }
        else{
            int count=1;
            while(count<pos-1){
                temp=temp->next;
                count++;
            }
            ptr->next=temp->next;
            ptr->prev= temp;
            (temp->next)->prev=ptr;
            temp->next=ptr;
        }
    }
}

void del (Node *&head, int pos){

    if(pos== 1) {
        Node* temp = head;
        head = head -> next;
        head->prev=NULL;
        temp -> next = NULL;
        temp -> prev = NULL;
        delete temp;
    }
    else if(pos<=len(head)&& pos>=1)
    { 
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        prev->prev=prev;
        curr -> next  = NULL;
        curr->prev=prev;
        delete curr;

    }
    else{
        cout<<"INVALID!"<<endl;
    }
}

int main(){

    Node* node1= new Node(10);

    Node* head= node1;

    print(head);

    cout<<len(head)<<endl;

    InsertatHead(head,5);

    print(head);

    cout<<len(head)<<endl;

    InsertatHead(head,4);

    print(head);

    cout<<len(head)<<endl;

    InsertatHead(head,3);

    print(head);

    cout<<len(head)<<endl;

    InsertatHead(head,2);

    print(head);

    cout<<len(head)<<endl;
 

    InsertatTail(head,tail,30);

    print(head);

    cout<<len(head)<<endl;

    cout<<"The tail is:<--"<<tail->data<<"-->"<<endl;

    InsertAtPosition(head,2,77);
    print(head);
    cout<<len(head)<<endl;

    InsertAtPosition(head,7,88);
    print(head);
    cout<<len(head)<<endl;

    InsertAtPosition(head,9,99);
    print(head);
    cout<<len(head)<<endl;

    InsertAtPosition(head,1,1);
    print(head);
    cout<<len(head)<<endl;

    del (head,1);
    print(head);
    cout<<len(head)<<endl;

    del (head,5);
    print(head);
    cout<<len(head)<<endl;

    del (head,8);
    print(head);
    cout<<len(head)<<endl;

    del (head,5);
    print(head);
    cout<<len(head)<<endl;


    return 0;

}