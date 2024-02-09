#include<bits/stdc++.h>
using namespace std;


int main(){

    queue<int> q;

    q.push(3);
    q.push(1);
    q.push(4);
    q.push(5);

        if(q.empty())
        cout<<"queue is empty!"<<endl;
    else
        cout<<"q is not empty!"<<endl;

    cout<<"The size of the queue is: "<<q.size()<<endl;

    q.pop();

    cout<<"The size of the queue is: "<<q.size()<<endl;

    cout<<"The front element is : "<<q.front()<<endl;

        q.pop();

    cout<<"The size of the queue is: "<<q.size()<<endl;

    cout<<"The front element is : "<<q.front()<<endl;
        q.pop();

    cout<<"The size of the queue is: "<<q.size()<<endl;

    cout<<"The front element is : "<<q.front()<<endl;
        q.pop();

    cout<<"The size of the queue is: "<<q.size()<<endl;

    cout<<"The front element is : "<<q.front()<<endl;

    if(q.empty())
        cout<<"queue is empty!"<<endl;
    else
        cout<<"q is not empty!"<<endl;
    



}