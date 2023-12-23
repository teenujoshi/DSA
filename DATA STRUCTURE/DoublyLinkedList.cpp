#include<iostream>
using namespace std;
class Node
{
     public:
     int value;
     Node* next;
     Node* previous;

     Node()
     {
          this->value = 0; 
          this->next = NULL;
          this->previous = NULL;
     }
     Node(int value)
     {
          this->value = value; 
          this->next = NULL;
          this->previous = NULL;
     }
};

class Doubly_Linked_List
{
     private:
          Node* head;
          Node* tail;
     public:
          Doubly_Linked_List()
          {
               head = NULL;
               tail = NULL;
          }
          void insertAtHead(Node &newnode)
          {
               if(head==NULL)
               {
                    head = &newnode;
                    tail = &newnode;
               }

               if(head!=NULL)
               {
                    newnode.previous = NULL;
                    newnode.next = head;
                    head->previous = &newnode;          
                    head = &newnode;
               }
          }
          void insertAtTail(Node &newnode)
          {
               if(tail==NULL)
               {
                    head = &newnode;
                    tail = &newnode;
               }

               if(tail!=NULL)
               {
                    newnode.next = NULL;
                    newnode.previous = tail;
                    tail->next = &newnode;
                    tail = &newnode;
               }
          }
          void insertAtPosition(Node &node, int position)
          {
               Node* traversalNode = head;
               for(int i=1; i<position-1; i++)
                    traversalNode = traversalNode->next;

               node.next = traversalNode->next;
               node.previous = traversalNode;
               traversalNode->next = &node;
               traversalNode = traversalNode->next;
               traversalNode->previous = &node;
          }
          void deleteAtHead()
          {
               if(isListEmpty())
               {
                    cout<<"Cannot delete at head when the list is empty!"<<endl<<endl;
               }
               else
               {  
                    head = head->next;
                    head->previous = NULL;
               }
          }
          void deleteAtTail()
          {
                if(isListEmpty())
               {
                    cout<<"Cannot delete at tail when the list is empty!"<<endl<<endl;
               }
               else
               {               
                    tail = tail->previous;
                    tail->next = NULL;
               }
          }
          void deleteAtPosition(int position)
          {
               if(position>size() || position == 0)
               {
                    cout<<"Wrong input! The position provided is either 0 or greater then the size of the linked list!"<<endl<<endl;
               }
               else
               {
                    Node* traversalNode = head;
                    for(int i=1; i<position-1; i++)
                         traversalNode = traversalNode->next;

                    traversalNode->next = traversalNode->next->next;
                    traversalNode->next->next->previous = traversalNode;


               }
          }
          int search(Node &node)
          {
               int count=0;
               for(Node* traversalNode = head ; traversalNode!=NULL ; traversalNode = traversalNode->next)
               {
                    count++;
                    if((traversalNode == &node) && (traversalNode->next == node.next) && (traversalNode->value == node.value && (traversalNode->previous == node.previous)))
                    {
                         cout<<"The provided node is present in the linked list at position: "<<count<<endl<<endl;
                         break;
                    }
               }

               if(count>=size())
               {
                    cout<<"The provided node is not present in the linked list! "<<endl<<endl;
               }

               return count;
          }
          int size()
          {
               int count=0;
               for(Node* traversalNode = head ; traversalNode!=NULL ; traversalNode = traversalNode->next)
               {
                    count++;          
               }

               return count;
          }
          void printLinkedList()
          {
               for(Node* traversalNode = head ; traversalNode->next!=NULL ; traversalNode = traversalNode->next)
               {
                    cout<<traversalNode->value<<" <-> ";          
               }
               cout<<tail->value<<endl<<endl;
          }
          void elementBeforePos(int position)
          {
               if(position<=1)
               {
                    cout<<"Wrong input! There is no element present at position "<<position<<endl;
               }
               else
               {
                    // Node* traversalNode = head;
                    // for(int i=1; i<position; i++)
                    //      traversalNode = traversalNode->next;

                    // cout<<"The element before "<<traversalNode->value<<" (position: "<<position<<") is: "<<traversalNode->previous->value<<endl<<endl;
                    // traversalNode = traversalNode->previous;
                    // cout<<traversalNode->value<<endl<<endl;

                    Node* traversalNode = head;
                    for(int i=1; i<position-1; i++)
                         traversalNode = traversalNode->next;

                    cout<<"The element before "<<traversalNode->next->value<<" (position: "<<position<<") is: "<<traversalNode->value<<endl<<endl;

               }
          }
          void elementAfterPos(int position)
          {
               if(position<1 || position>size())
               {
                    cout<<"Wrong input! There is no element present at position "<<position<<endl;
               }
               else
               {
                    Node* traversalNode = head;
                    for(int i=1; i<position; i++)
                         traversalNode = traversalNode->next;

                    cout<<"The element after "<<traversalNode->value<<" (position: "<<position<<") is: "<<traversalNode->next->value<<endl<<endl;
               }
          }
          bool isListEmpty()
          {
               if(size()==0 || head == NULL || tail == NULL)
                    return true;
               else
                    return false;
          }

};
int main()
{
     Node n1(1);
     Node n2(2);
     Node n3(3);
     Node n4(4);
     Node n5(5);
     Node n6(6);
     Node n7(7);
     Node n8(8);
     Doubly_Linked_List dll;
     dll.isListEmpty()? cout<<endl<<"The linked list is empty!\n\n" : cout<<endl<<"The linked list is not empty!\n\n" ;
     dll.insertAtHead(n1);
     dll.insertAtTail(n2);
     dll.printLinkedList();
     cout<<endl<<endl;
     dll.insertAtTail(n3);
     dll.printLinkedList();
     cout<<endl<<endl;
     dll.insertAtPosition(n4,3);
     dll.printLinkedList();
     cout<<endl<<endl;
     dll.insertAtPosition(n5,2);
     dll.printLinkedList();
     cout<<endl<<endl;
     dll.insertAtPosition(n6,4);
     dll.printLinkedList();
     cout<<endl<<endl;
     cout<<"The size of the linked list is: "<<dll.size()<<endl;
     dll.search(n4);
     dll.search(n8);
     dll.elementAfterPos(4);
     dll.elementBeforePos(2);
     // dll.deleteAtHead();
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.deleteAtTail();
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.deleteAtPosition(3);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.deleteAtPosition(2);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.deleteAtPosition(7);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.insertAtTail(n7);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.insertAtTail(n8);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     // dll.deleteAtPosition(4);
     // dll.printLinkedList();
     // cout<<endl<<endl;
     return 0;
}