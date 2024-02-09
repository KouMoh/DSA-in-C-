#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int data;
    Stack* next;
    Stack* top = NULL;

    Stack(int value) {
        this->data = value;
        this->next = NULL;
    }

~Stack() {
    if (next != NULL) {
        delete next;
        next = NULL;
    }
}

    void push(int element) {
        Stack* ptr = new Stack(element);
        if (top == NULL) {
            top = ptr;
            top->next = NULL;
        }
        else {
            ptr->next = top;
            top = ptr;
        }
    }

    void pop() {
        if (top == NULL)
            cout << "UNDERFLOW!" << endl;
        else {
            Stack* temp = top;
            top = top->next;
            cout<<temp->data<<" is DELETED!"<<endl;
            delete temp;
        }
    }

int peek() {
    if (top == NULL) {
        cout << "Stack is empty!";
        return -1;
    }
    else {
        return top->data;
    }
}

    bool IsEmpty() {
        return top == NULL;
    }
};

int main() {
    Stack st(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    
    cout<<"The top element is: "<<st.peek()<<endl;
    st.pop();
    cout<<"The top element is: "<<st.peek()<<endl;
    if(st.IsEmpty()){
        cout<<"Empty Stack!"<<endl;
    } else{
        cout<<"Stack is not empty!"<<endl;
    }

    return 0;
}