#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
     char *array;
     int top;
     int capacity;

public:
     Stack();
     Stack(int capacity);
     void push(char value);
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
     array = new char(capacity);
     top = -1;
}
void Stack::push(char value)
{
     if (top > capacity - 1)
     {
          cout << "Cannot push more items, the stack is full!";
          return;
     }

     else
          array[++top] = value;
}
void Stack::pop()
{
     if (top < 0)
     {
          cout << "Cannot pop any element as the stack is empty!";
          return;
     }

     else

          int x = array[top--];
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

bool match(char a, char b)
{
     if (a == '(' && b == ')')
          return true;

     else if (a == '{' && b == '}')
          return true;

     else if (a == '[' && b == ']')
          return true;

     return false;
}
bool parenthesisMatching(string st)
{
     int size = st.size();

     Stack s(size);

     for (int i = 0; i < size; i++)
     {
          if (st[i] == '(' || st[i] == '{' || st[i] == '[')
          {
               s.push(st[i]);
          }

          else if (st[i] == ')' || st[i] == '}' || st[i] == ']')
          {
               if (s.isEmpty())
                    return false;

               if (!match(s.peek(), st[i]))
                    return false;

               s.pop();
          }
     }
     if (s.isEmpty())
          return true;

     else
          return false;
}
int main()
{
     string str = "[{}{{{()}]";

     if (parenthesisMatching(str))
          cout << "The parenthesis are balanced!";

     else
          cout << "The parenthesis are not balanced!";
     return 0;
}