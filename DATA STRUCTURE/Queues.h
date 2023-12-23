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
          cout << traversalNode->value << " -> ";
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