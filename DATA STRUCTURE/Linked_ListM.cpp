#include<iostream>
using namespace std;
class node{
    public:
    int value;
    node* next;
};

class SinglyLink{
    
	node *head;
	node *tail;
public:
  SinglyLink()
{
	head = NULL;
	tail = NULL;
}
  SinglyLink(const int& val)
{
    head->value=val;
    tail=NULL;
}
  SinglyLink(SinglyLink& s)
{
    head=s.head;
    tail=s.tail;
}

void InsertAtHead(const int& value)
{
	node * newN = NULL;

	 newN = new node;
	 newN->value = value;

	 newN->next = head;
	 head =  newN;

	if(tail==NULL)
		tail =  newN;
}

void InsertAtTail(const int& value)
{
	node * newN = NULL;

	 newN = new node;
	 newN->value = value;
	 newN->next = NULL;

	if(head==NULL)
	{
		head =  newN;
		tail =  newN; 
	}
	else
	{
		tail->next =  newN;
		tail =  newN;		

	}	
}

// void   InsertAtPosition(const int& value)
// {

// 	node* current = searchNode(value);

// 	if(current)
// 	{
// 		int value;
// 		cout<<"Enter value to insert: ";
// 		cin>>value;
// 		node*  newN = new node;

// 		 newN->value = value;
// 		 newN->next = current->next;
// 		current->next =  newN;
// 	}
// 	else
// 		cout<<"Cannot insert\n";

// }

void   InsertAtPosition(const int& value, int position)
{
			node* current = searchNode(value);
	//node node(value);
           node* current = head;
          for(int i=1; i<position-1; i++)
          current = current->next;

          newN.next = current->next;
          current->next = newN;

	// node* current = searchNode(value);

	// if(current)
	// {
	// 	int value,position;
	// 	cout<<"Enter position in which you want  to insert: ";
	// 	cin>>position;
	// 	cout<<"Enter value to insert: ";
	// 	cin>>value;
	// 	node*  newN = new node;

	// 	 newN->value = value;
	// 	 newN->next = current->next;
	// 	current->next =  newN;
	// }
	// else
	// 	cout<<"Cannot insert\n";

}

void   display() const
{
	node *current = NULL;
	current = head;
    cout<<"*****************"<<endl;
	while(current!=NULL)
	{
		cout<<current->value<<"->";
		current = current->next;
	}
	cout<<"NULL"<<endl;
    cout<<"*****************";
}

void deleteList()
{
	node *current = NULL;
	while(head != NULL)
	{
		current = head;
		head = head->next;
		delete current;
	}
	tail = NULL;
}

  ~SinglyLink()
{
	deleteList();
}

void   deleteAtHead()
{
	node *current = head;
	head = head->next;

	if(current!= NULL)
		delete current;
}

void   deleteAtTail()
{
	node *current = head;
	node *prev = NULL;
	if (current == NULL)
	{
		cout<<"Empty list cannot delete\n";
		return;
	}

	if(current->next == NULL)
	{
		head = NULL;
		tail = NULL;
		delete current;
		return;
	}

	for( ; current->next; current = current->next)
	{
		prev = current;
	}
	delete current;
	prev->next = NULL;
	tail = prev;
}
 
node* searchNode(const int& value)
{
	node *current = NULL;
	current = head;

	while(current!=NULL)
	{
		if(current->value == value)
			return current;
		current = current->next;
	}
	return NULL;
}

void deleteAtPosition(const int& value,int position)
{
   
	node* current = head;
	node* prev = NULL;

	if(current == NULL)
	{
		cout<<"List empty cannot delete\n";
		return;
	}
	if(current->next == NULL)
	{
		if(current->value == value)
		{
			head = current->next;
			delete current;
			tail = NULL;
			return;
		}
		else
		{
			cout<<"Node not found\n";
			return;
		}
	}
	
	for( ; current->next; )
	{
		if(current->value==value)
		{
			if(prev==NULL)
			{
				head = current->next;
				delete current;
				return;
			}
			prev->next = current->next;
			delete current;
			return;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	cout<<"Node not found\n";

}
node* prevelem(const int& value)
{
    static int counter=0;
    node *prev = NULL;
    node *current = NULL;
	current = head;
	while(current!=NULL)
	{
        counter++;
		if(current->value == value)
        {
            current=head;
            for(int i=0;i<counter-1;i++)
            {
                prev=current;
                current=current->next;
            }
            cout<<prev->value<<endl;
            return prev;
        }
        current = current->next;
	}
    return NULL;
}
node* nextelem(const int& value)
{
    node *after = NULL;
    node *current = NULL;
	current = head;
	while(current!=NULL)
	{
		if(current->value == value)
        {
            after = current->next;
            cout<<after->value<<endl;
            return after;
        }
	}
    return NULL;
}
bool isEmpty(){
    return this->head==NULL;

}
void concat(SinglyLink& list)
{
    tail->next = list.head;
    tail=list.tail;
}
int size(){
    static int count = 0;
    node* current = head; 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count;
}
};
int main()
{
	SinglyLink link1,link2;
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
        cout<<"Press 13 to Concatenate "<<endl;        
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
				link1.InsertAtHead(value);
                cout<<endl;
				break;
			case 2 :
				cout<<"Enter value: ";
				cin>>value;
				link1.InsertAtTail(value);
                cout<<endl;
				break;
			case 3:
				cout<<"Enter position in which you want to insert: ";
				cin>>position;
				cout<<"Enter value after which you want to attach node: ";
				cin>>value;
			    
				link1.InsertAtPosition(value,position);
                cout<<endl;
				break;
			case 4 :
				link1.deleteAtHead();
                cout<<endl;
				break;
			case 5 :
				link1.deleteAtTail();
                cout<<endl;
				break;
			case 6 :
				cout<<"Enter position in which you want to delete: ";
				cin>>position;
				cout<<"Enter value to delete: ";
				cin>>value;
				link1.deleteAtPosition(value,position);
                cout<<endl;
				break;
			case 7:
				cout<<"Enter value to search: ";
				cin>>value;
				if(link1.searchNode(value))
					cout<<"Node present\n"<<endl;
				else
					cout<<"Node absent\n"<<endl;
				break;
            case 8:
                cout<<link1.size()<<endl;
                break;
            case 9:
                link1.display();
                break;
            case 10:
                cout<<"Enter value to search: ";
				cin>>value;
                link1.prevelem(value);
                break;
            case 11:
                cout<<"Enter value to search: ";
				cin>>value;
                link1.nextelem(value);
                break;
            case 12:
                if(link1.isEmpty())
                cout<<"Empty"<<endl;
                else
                cout<<"Not Empty"<<endl;
				break;
            case 13:
                cout<<"Enter 3 value in 2nd List: ";
                for(int i=0;i<3;i++)
                {
			        cin>>value;
				    link2.InsertAtTail(value);
                }
                link1.concat(link2);
                link1.display();
				break;
			default:
				cout<<"Invalid choice\n";
				break;
		}
	}while(choice!=0);
	return 0;
}