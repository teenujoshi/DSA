#include <iostream>
using namespace std;

class Stack
{
private:
     int *array;
     int top;
     int capacity;

public:
     Stack();
     Stack(int capacity);
     void push(int value);
     void pop();
     int peek();
     bool isEmpty();
     int size();
};

Stack::Stack()
{
     top = -1;
     array = new int(1);
}
Stack::Stack(int capacity)
{
     this->capacity = capacity;
     array = new int(capacity);
     top = -1;
}
void Stack::push(int value)
{
     if (top >= capacity - 1)
     {
          cout << "\nCannot push more items, the stack is full!";
          return;
     }

     else
     {
          array[++top] = value;
          cout << value << "\n pushed into stack \n";
     }
}
void Stack::pop()
{
     if (top < 0)
     {
          cout << "\nCannot pop any element as the stack is empty!";
          return;
     }

     else
     {
          int x = array[top--];
          cout << x << "\n -- The topmost element popped from the stack \n";
     }
}
int Stack::peek()
{
     if (isEmpty())
     {
          cout << "\nThe stack is empty";
          return 0;
     }
     else
     {
          int x = array[top];
          return x;
     }
}
bool Stack::isEmpty()
{
     return (top < 0);
}
int Stack::size()
{
     return top + 1;
}

int main()
{
     Stack s;
     s.push(10);
     s.push(20);
     s.push(30);
     s.pop();

     cout << "\nTop element is : " << s.peek() << endl;

     cout << "\nElements present in the stack are: ";
     while (!s.isEmpty())
     {
          cout << s.peek() << "   ";
          s.pop();
     }
     return 0;
}