#include <iostream>
using namespace std;

class Stack {
public:
  int *arr;
  int size;
  int top;

  // constrcutor

  Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int element) {

    if (top == (size - 1)) {
      cout << "OVERFLOW!" << endl;
      return;
    } else {
      top++;
      arr[top] = element;
    }
  }

  void pop() {
    if (top == -1) {
      cout << "UNDERFLOW!" << endl;
      return;
    } else {
      cout << "The element'" << arr[top] << "' has been deleted" << endl;
      top--;
    }
  }

  int peek() {
    if (top >= 0) {
      return arr[top];
    } else {
      cout << "stack is empty!" << endl;
      return -1;
    }
  }

  bool IsEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
};

int main() {
  Stack st(5);
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  cout << "Top element:" << st.peek() << endl;

  st.pop();

  cout << "Top element:" << st.peek() << endl;

  if (st.IsEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

  st.pop();

  cout << "Top element:" << st.peek() << endl;

  if (st.IsEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

  st.pop();

  cout << "Top element:" << st.peek() << endl;

  if (st.IsEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

    st.pop();

  cout << "Top element:" << st.peek() << endl;

  if (st.IsEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

    st.pop();

  cout << "Top element:" << st.peek() << endl;

  if (st.IsEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

  return 0;
}
