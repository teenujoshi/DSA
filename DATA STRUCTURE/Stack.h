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
     void printStack();
     void rollStack(int noOfTimes);
};

Stack::Stack()
{
     top = -1;
}
Stack::Stack(int capacity)
{
     this->capacity = capacity;
     array = new int(capacity);
     top = -1;
}
void Stack::push(int value)
{
     if (top > capacity - 1)
     {
          cout << "Cannot push more items, the stack is full!";
          return;
     }

     else
     {
          array[++top] = value;
          // cout << value << " pushed into stack \n";
     }
}
void Stack::pop()
{
     if (top < 0)
     {
          cout << "Cannot pop any element as the stack is empty!";
          return;
     }

     else
     {
          int x = array[top--];
          // cout << x << " -- The topmost element popped from the stack \n";
     }
}
int Stack::peek()
{
     if (isEmpty())
     {
          cout << "The stack is empty";
          return 0;
     }
     else
          return array[top];
}
bool Stack::isEmpty()
{
     return (top < 0);
}
int Stack::size()
{
     return top + 1;
}
void Stack::printStack()
{
     for (int i = top; i >= 0; i--)
     {
          cout << array[i] << "   ";
     }
}
void Stack::rollStack(int noOfTimes)
{
     for (int i = 0; i < noOfTimes; i++)
     {
          int toptemp = 0;
          int temp;
          temp = array[0];
          for (int j = 0; j < size() - 1; j++)
          {
               array[toptemp] = array[toptemp + 1];
               toptemp++;
          }
          array[top] = temp;
     }
}
