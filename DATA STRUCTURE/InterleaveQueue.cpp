#include <iostream>
using namespace std;

class Node
{
public:
     int value;
     Node *next;

     Node();
     Node(int value);
};
Node::Node()
{
     this->value = 0;
     this->next = NULL;
}
Node::Node(int value)
{
     this->value = value;
     this->next = NULL;
}

class Queue
{
private:
     Node *rear;
     Node *front;

public:
     Queue();
     void EnqueueAtRear(int value);
     void DequeueAtFront();
     int size();
     void printQueue();
     bool isQueueEmpty();
     int Front();
     int Rear();
};

Queue::Queue()
{
     rear = NULL;
     front = NULL;
}
void Queue::EnqueueAtRear(int value)
{
     Node *newnode = NULL;
     newnode = new Node;
     newnode->value = value;
     if (rear == NULL)
     {
          front = newnode;
          rear = newnode;
     }

     if (rear != NULL)
     {
          rear->next = newnode;
          rear = newnode;
     }
}
void Queue::DequeueAtFront()
{
     if (isQueueEmpty())
     {
          cout << "Cannot delete at front when the queue is empty!" << endl
               << endl;
     }
     else
          front = front->next;
}
bool Queue::isQueueEmpty()
{
     if (size() == 0 || front == NULL || rear == NULL)
          return true;
     else
          return false;
}
int Queue::size()
{
     int count = 0;
     for (Node *traversalNode = front; traversalNode != NULL; traversalNode = traversalNode->next)
     {
          count++;
     }

     return count;
}
void Queue::printQueue()
{
     cout << "\n\n";
     for (Node *traversalNode = front; traversalNode->next != NULL; traversalNode = traversalNode->next)
     {
          cout << traversalNode->value << "  ";
     }
     cout << rear->value << endl
          << endl;
}
int Queue::Front()
{
     return front->value;
}
int Queue::Rear()
{
     return rear->value;
}

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
void InterleavingQueues(Queue q)
{
     int firstHalf, secondHalf;

     if (q.size() % 2 == 0)
     {
          firstHalf = q.size() / 2;
          secondHalf = q.size() / 2;
     }

     if (q.size() % 2 != 0)
     {
          firstHalf = (q.size() / 2) + 1;
          secondHalf = q.size() - firstHalf;
     }

     Stack shalf1(firstHalf);
     Stack shalf2(secondHalf);
     Stack shalftemp1(firstHalf);
     Stack shalftemp2(secondHalf);

     for (int i = 0; i < firstHalf; i++)
     {
          shalf1.push(q.Front());
          q.DequeueAtFront();
     }

     for (int i = 0; i < secondHalf; i++)
     {
          shalf2.push(q.Front());
          q.DequeueAtFront();
     }

     for (int i = 0; i < firstHalf; i++)
     {
          shalftemp1.push(shalf1.peek());
          shalf1.pop();
     }

     for (int i = 0; i < secondHalf; i++)
     {
          shalftemp2.push(shalf2.peek());
          shalf2.pop();
     }

     Queue q1;
     while (!shalftemp1.isEmpty() && !shalftemp2.isEmpty())
     {
          q1.EnqueueAtRear(shalftemp1.peek());
          shalftemp1.pop();
          q1.EnqueueAtRear(shalftemp2.peek());
          shalftemp2.pop();
     }
     if (firstHalf != secondHalf)
          q1.EnqueueAtRear(shalftemp1.peek());

     q1.printQueue();
}

int main()
{
     Queue q;

     q.EnqueueAtRear(10);
     q.EnqueueAtRear(2);
     q.EnqueueAtRear(35);
     q.EnqueueAtRear(4);
     q.EnqueueAtRear(5);
     q.EnqueueAtRear(6);
     q.EnqueueAtRear(34);
     //q.EnqueueAtRear(54);

     InterleavingQueues(q);

     return 0;
}