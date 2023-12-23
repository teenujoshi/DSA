#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(){
        val = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
    Node(int val , Node*next , Node * prev){
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};
class LinkedList{
    public:
    Node * head;
    Node * tail;
    int currentNode = 0;
    LinkedList(){
        head = NULL;
        tail = NULL;
        currentNode = 0;
    }
    LinkedList(Node*n){
        currentNode = 1;
        head = n;
        tail = n;
    }
    void traverse(){
        Node *temporary = head;
        while(temporary){
            cout << temporary->val<<" ";
            temporary = temporary->next;
        }
        cout << endl;
    }
    void insert(Node * n , int pos){
        if(pos == 1){
            if(currentNode == 0){
                head = n;
                tail = n;
            }
            else{
                n->next = head;
                head->prev = n;
                head = n;
                n->prev = NULL;
            }
        }
        else if(pos == currentNode+1){
            n->next = NULL;
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        else{
            Node * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            n->next = prev->next;
            n->prev = prev;
            prev->next = n;
            n->next->prev = n;
        }
        currentNode++;
    }
    void deleteNode(int pos){
        if(pos == 1){
            head = head->next;
            head->prev = NULL;
        }
        else if(pos == currentNode){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            Node * prev = head;
            for(int i = 2 ; i<pos ; i++){
                prev = prev->next;
            }
            Node * curr = prev->next;
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        currentNode--;
    }
    int searchElem(int elem){
        int pos = -1;
        Node * temporary = head;
        int currpos = 1;
        while(temporary){
            if(temporary->val == elem){
                pos = currpos;
                break;
            }
            currpos++;
            temporary = temporary->next;
        }
        return pos;
    }
    int getSize(){
        return currentNode;
    }
    bool isEmpty(){
        if(currentNode == 0) return true;
        return false;
    }
    int printElemBeforePos(int pos){
        if(pos == 1){
            cout << "No element exist before position 1"<< endl;
            exit(100);
        }
        Node * temporary = head;
        for(int i = 2 ; i<pos ; i++){
            temporary = temporary->next;
        }
        return temporary->val;
    }
    int printElemAfterPos(int pos){
        if(pos == currentNode){
            cout << "No element exist after end position"<< endl;
            exit(100);
        }
        Node * temporary = head;
        for(int i = 2 ; i<=pos+1 ; i++){
            temporary = temporary->next;
        }
        return temporary->val;
    }
    void concatenate(LinkedList & l){
        tail->next = l.head;
        l.head->prev = tail;
        l.tail->next = NULL;
        tail = l.tail;
    }
    
};
int main(){
    LinkedList l,l1;
    int choice = 1;
    do{
        Node * node = new Node();
        int Choice,pos,val,elem;
        cout << "1. Insert an element at head \n";
        cout << "2. Insert an element at tail \n";
        cout << "3. Insert an element at a position \n";
        cout << "4. Delete an element at head \n";
        cout << "5. Delete an element at tail \n";
        cout << "6. Delete an element at a position \n";
        cout << "7. Search for an element in Linked List \n";
        cout << "8. Print size of linked list \n";
        cout << "9. Print linked list \n";
        cout << "10. Print element before a position \n";
        cout << "11. Print element after a position \n";
        cout << "12. Check if list is empty or not \n";
        cout << "13. concatenate \n";
        cout << "14. Exit \n";
        cout << "Enter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , 1);
            break;
        case 2:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , l.currentNode+1);
            break;
        case 3:
            cout << "enter the value of node : ";
            cin >> node->val;
            cout << "enter the position : ";
            cin >> pos;
            l.insert(node,pos);
            break;
        case 4:
            l.deleteNode(1);
            break;
        case 5:
            l.deleteNode(l.currentNode);
            break;
        case 6:
            cout << "enter the position : ";
            cin >> pos;
            l.deleteNode(pos);
            break;
        case 7:
            cout << "enter the node value to be searched: ";
            cin >> val;
            pos = l.searchElem(val);
            if(pos == -1){
                cout << "Element not found!!"<< endl;
            }
            else{
                cout << "Element found at position: " << pos << endl;
            }
            break;
        case 8:
            cout << "The size of linked list is: " << l.getSize();
            break;
        case 9:
            l.traverse();
            break;
        case 10:
            cout << "Enter the position: ";
            cin >> pos;
            cout << l.printElemBeforePos(pos);
            break;
        case 11:
            cout << "Enter the position: ";
            cin >> pos;
            cout << l.printElemAfterPos(pos);
            break;
        case 12:
            l.isEmpty()?cout << "List is empty"<<endl:cout <<"List is not empty"<<endl;
            break;
        case 13:
            cout << "Enter the number of elements in the list to be concatenated: ";
            cin >> val;
            pos = 1;
            while(pos <= val){
                cout << "enter the value of " << pos << " node: ";
                cin >> elem;
                node = new Node(elem);
                l1.insert(node,pos);
                pos++;
            }
            l.concatenate(l1);
            break;
        
        case 14:
            choice = 0;
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Wrong choice entered, Exiting program!!!"<<endl;
            choice = 0;
        }
        cout << endl<<endl;
    }while(choice);
    return 0;
}