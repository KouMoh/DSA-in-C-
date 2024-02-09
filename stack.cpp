#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <int> s;

    s.push(1);
    s.push(2);

    cout<<"size of stack is: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;
    s.pop();
    cout<<"size of stack is: "<<s.size()<<endl;
    cout<<"top: "<<s.top()<<endl;
    s.pop();
    cout<<"size of stack is: "<<s.size()<<endl;

    if (s.empty()){
        cout<<"Stack is empty"<<endl;
    } else{
        cout<<"Stack is not empty"<<endl;

    }
    return 0;
}