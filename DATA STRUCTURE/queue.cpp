#include <iostream>
using namespace std;

class Node
{
public:
     int value;
     Node *next;

     Node(){
        this->value = 0;
        this->next = NULL;
     }
     Node(int value){
        this->value = value;
        this->next = NULL;
     }
};
class Queues
{
private:
     Node *rear;
     Node *front;

public:
     Queues(){
        rear = NULL;
        front = NULL;
     }
     void EnqueueAtRear(int value){
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
     void DequeueAtFront(){
        if (isQueueEmpty())
        {
            cout << "Cannot delete because the queue is empty!" << endl
                << endl;
        }
        else
            front = front->next;
     }
     int size(){
        int count = 0;
        for (Node *traversalNode = front; traversalNode != NULL; traversalNode = traversalNode->next)
        {
            count++;
        }

        return count;
     }
     void printQueue(){
        cout << "\n\n";
        for (Node *traversalNode = front; traversalNode->next != NULL; traversalNode = traversalNode->next)
        {
            cout << traversalNode->value << " ";
        }
        cout << rear->value << endl
            << endl;
     }
     bool isQueueEmpty(){
        if (size() == 0 || front == NULL || rear == NULL)
          return true;
        else
          return false;
     }
     int Front(){
        return front->value;
     }
     int Rear(){
        return rear->value;
     }
};
int main()
{

     Queues q;

     int n, choice, position;
     do
     {
          cout << "\n1.Enqueue----------Insert an element at rear in the queue" << endl;
          cout << "2.Dequeue----------Delete an element at front in the queue" << endl;
          cout << "3.Empty---------Check if queue is empty or not" << endl;
          cout << "4.Size--------Print size of the queue" << endl;
          cout << "5.Print the queue" << endl;
          cout << "Press 0 to Exit" << endl;
          cin >> choice;

          switch (choice)
          {
          case 1:
          {
               cout << "Enter the value to be inserted at rear: ";
               cin >> n;
               q.EnqueueAtRear(n);
               break;
          }
          case 2:
          {
               cout << "The queue after dequing at rear: ";
               q.DequeueAtFront();
               q.printQueue();
               cout << endl
                    << endl;
               break;
          }
          case 3:
          {
               if(q.isQueueEmpty())
               { 
                cout << endl<< "The queue is empty!\n\n";
               }
                else
                    cout << endl<< "The queue is not empty!\n\n";
                                       
               break;
          }
          case 4:
          {
               cout << "The size of the queue is: " << q.size() << endl;
               break;
          }
          case 5:
          {
               cout << "The queue is: " << endl;
               q.printQueue();
               cout << endl
                    << endl;
               break;
          }

          default:
          {
               cout << "Enter a valid input!" << endl;
               break;
          }
          }

     } while (choice != 0);

     return 0;
}




























// int main(){
//     Queue q;
//     int choice,position,n;
//     do{
//         cout<<"1: EnqueueAtRear"<<endl;
//         cout<<"2: DequeueAtFront"<<endl;
//         cout<<"3: Size"<<endl;
//         cout<<"4: isQueueEmpty"<<endl;
//         cout<<"5: PrintQueue"<<endl;
//         cout<<"6: Front"<<endl;
//         cout<<"7: Rear"<<endl;
//         cout<<"0 to exit"<<endl;
//         cout<<"Enter your choice"<<endl;
//         cin>>choice;

//         switch(choice){
//             case 1:
//         }
//     }
// }
