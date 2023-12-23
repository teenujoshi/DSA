#include<iostream>
using namespace std;
class Node
{
     public:
     int value;
     Node* next;

     Node()
     {
          this->value = 0; 
          this->next = NULL;
     }
     Node(int value)
     {
          this->value = value; 
          this->next = NULL;
     }
};
class Singly_Linked_List
{
     private:

     Node* head;
     Node* tail;

     public:

     Singly_Linked_List()
     {
          head = NULL;
          tail = NULL;
     }
     void insertAtHead(const int& value)
     {
          Node newnode(value);
          if(head==NULL)
          {
               head = &newnode;
               tail = &newnode;
          }

          if(head!=NULL)
          {
               newnode.next = head;
               head = &newnode;
          } 
     }
     void insertAtTail(const int& value)
     {
          Node newnode(value);
          if(tail==NULL)
          {
               head = &newnode;
               tail = &newnode;
          }

          if(tail!=NULL)
          {
               tail->next = &newnode;
               tail = &newnode;
          }
     }
     void insertAtPosition(const int& value, int position)
     {
          Node node(value);
           Node* currentNode = head;
          for(int i=1; i<position-1; i++)
          currentNode = currentNode->next;

          node.next = currentNode->next;
          currentNode->next = &node;
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
               for(Node* currentNode = head ; currentNode!=NULL ; currentNode = currentNode->next)
               {
                    if(currentNode->next->next==NULL)
                    {
                         tail = currentNode;
                         currentNode->next = NULL;
                         break;
                    }
                    
               }
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
               Node* currentNode = head;
               for(int i=1; i<position-1; i++)
                    currentNode = currentNode->next;

               currentNode->next = currentNode->next->next;
          }
     }
     int search(const int& value)
     {
          Node node(value);
          int count=0;
          for(Node* currentNode = head ; currentNode!=NULL ; currentNode = currentNode->next)
          {
               count++;
               if((currentNode == &node) && (currentNode->next == node.next) && (currentNode->value == node.value))
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
          for(Node* currentNode = head ; currentNode!=NULL ; currentNode = currentNode->next)
          {
               count++;          
          }

          return count;
     }
     void printLinkedList()
     {
          Node *currentNode = NULL;
               currentNode = head;
          cout<<"*****************"<<endl;
               while(currentNode!=NULL)
               {
                    cout<<currentNode->value<<"->";
                    currentNode = currentNode->next;
               }
               cout<<"NULL"<<endl;
          cout<<"*****************";
          // for(Node* currentNode = head ; currentNode->next!=NULL ; currentNode = currentNode->next)
          // {
          //      cout<<currentNode->value<<" -> ";          
          // }
          // cout<<tail->value<<endl;
     }
     void elementBeforePos(int position)
     {
          if(position<=1)
          {
               cout<<"Wrong input! There is no element present at position "<<position<<endl;
          }
          else
          {
               Node* currentNode = head;
               for(int i=1; i<position-1; i++)
                    currentNode = currentNode->next;

               cout<<"The element before "<<currentNode->next->value<<" (position: "<<position<<") is: "<<currentNode->value<<endl<<endl;}
     }
     void elementAfterPos(int position)
     {
          if(position<1 || position>size())
          {
               cout<<"Wrong input! There is no element present at position "<<position<<endl;
          }
          else
          {
               Node* currentNode = head;
               for(int i=1; i<position; i++)
                    currentNode = currentNode->next;

               cout<<"The element after "<<currentNode->value<<" (position: "<<position<<") is: "<<currentNode->next->value<<endl<<endl;
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
	Singly_Linked_List LL;
	int value, choice,position;
	do
	{
		cout<<"Press 1 to Insert at Head"<<endl;
		cout<<"Press 2 to Insert at Tail"<<endl;
		cout<<"Press 3 to Insert at a Position"<<endl;
		cout<<"Press 4 to Delete at Head"<<endl;
		cout<<"Press 5 to Delete at Tail"<<endl;
		cout<<"Press 6 to Delete at a Position"<<endl;
		cout<<"Press 7 to Search for Element"<<endl;
		cout<<"Press 8 to Print size"<<endl;
		cout<<"Press 9 to Print Linked List"<<endl;
		cout<<"Press 10 to Print element before a position"<<endl;
		cout<<"Press 11 to Print element after a position"<<endl;        
		cout<<"Press 12 to Check if Linked List is empty or not"<<endl;
        //cout<<"Press 13 to Concatenate "<<endl;        
		cout<<"Press 0 to Exit"<<endl;
        cout<<"*****************"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 0:
				break;
			case 1 :
				cout<<"Enter value: ";
				cin>>value;
				LL.insertAtHead(value);
                cout<<endl;
				break;
			case 2 :
				cout<<"Enter value: ";
				cin>>value;
				LL.insertAtTail(value);
                cout<<endl;
				break;
			case 3:
				cout<<"Enter value after which you want to attach node: ";
				cin>>value;
                    cout<<"Enter position in which you want to attach node: ";
				cin>>position;
				LL.insertAtPosition(value,position);
                cout<<endl;
				break;
			case 4 :
				LL.deleteAtHead();
                cout<<endl;
				break;
			case 5 :
				LL.deleteAtTail();
                cout<<endl;
				break;
			case 6 :
				cout<<"Enter value to delete: ";
				cin>>value;
				LL.deleteAtPosition(value);
                cout<<endl;
				break;
			case 7:
				cout<<"Enter value to search: ";
				cin>>value;
				if(LL.search(value))
					cout<<"Node present\n"<<endl;
				else
					cout<<"Node absent\n"<<endl;
				break;
            case 8:
                cout<<LL.size()<<endl;
                break;
            case 9:
                LL.printLinkedList();
                break;
            case 10:
                cout<<"Enter value to search: ";
				cin>>value;
                LL.elementBeforePos(value);
                break;
            case 11:
                cout<<"Enter value to search: ";
				cin>>value;
                LL.elementAfterPos(value);
                break;
            case 12:
                if(LL.isListEmpty())
                cout<<"Empty"<<endl;
                else
                cout<<"Not Empty"<<endl;
				break;
          //   case 13:
          //       cout<<"Enter 3 value in 2nd List: ";
          //       for(int i=0;i<3;i++)
          //       {
		// 	        cin>>value;
		// 		    //link2.insertAtTail(value);
          //       }
          //       //LL.concat(link2);
          //       LL.printLinkedList();
		// 		break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while(choice!=0);
	return 0;
}





























/*
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
     Singly_Linked_List sll;
     sll.isListEmpty()? cout<<endl<<"The linked list is empty!\n\n" : cout<<endl<<"The linked list is not empty!\n\n" ;
     sll.insertAtHead(n1);
     sll.insertAtTail(n2);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtTail(n3);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtPosition(n4,3);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtPosition(n5,2);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtPosition(n6,4);
     sll.printLinkedList();
     cout<<endl<<endl;
     cout<<"The size of the linked list is: "<<sll.size()<<endl;
     sll.search(n4);
     sll.search(n8);
     sll.elementAfterPos(4);
     sll.elementBeforePos(2);
     sll.deleteAtHead();
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.deleteAtTail();
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.deleteAtPosition(3);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.deleteAtPosition(2);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.deleteAtPosition(7);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtTail(n7);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.insertAtTail(n8);
     sll.printLinkedList();
     cout<<endl<<endl;
     sll.deleteAtPosition(4);
     sll.printLinkedList();
     cout<<endl<<endl;
     return 0;
}*/