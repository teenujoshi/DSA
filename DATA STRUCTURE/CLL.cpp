#include <iostream>
using namespace std;
template <typename T> class Node{
    public:
    T val;
    Node* next;
    Node(){
        val = 0;
        next = NULL;
    }
    Node(T val){
        this->val = val;
        next = NULL;
    }
    Node(T val , Node*next){
        this->val = val;
        this->next = next;
    }
};
template <typename T> class LinkedList{
    public:
    Node <T>* cursor;
    int currnodes = 0;
    LinkedList();
    LinkedList(Node<T>* n);
    void traverse();
    void insert(Node<T> * n , int pos);
    void deleteNode(int pos);
    int searchElem(int elem);
    int getSize();
    bool isEmpty();
    int printElemBeforePos(int pos);
    int printElemAfterPos(int pos);
    void concatenate(LinkedList<T>& l);
};
template<typename T> LinkedList<T> ::LinkedList(){
    cursor = NULL;
    currnodes = 0;
}
template<typename T> LinkedList<T> ::LinkedList(Node<T> * n){
    currnodes = 1;
    cursor = n;
}
template<typename T> void LinkedList<T> ::traverse(){
    Node<T>*temporary = cursor->next->next;
    cout << cursor->next->val<<" ";
    while(temporary != cursor->next){
        cout << temporary->val<<" ";
        temporary = temporary->next;
    }
    cout << endl;
}
template<typename T> void LinkedList<T> ::insert(Node<T> * n , int pos){
    if(pos == 1){
        if(currnodes == 0){
            cursor = n;
            cursor->next = n;
        }
        else{
            n->next = cursor->next;
            cursor->next = n;
        }
    }
    else if(pos == currnodes+1){
        n->next = cursor->next;
        cursor->next = n;
        cursor = n;
    }
    else{
        Node<T> * prev = cursor->next;
        for(int i = 2 ; i<pos ; i++){
            prev = prev->next;
        }
        n->next = prev->next;
        prev->next = n;
    }
    currnodes++;
}
template<typename T> void LinkedList<T> ::deleteNode(int pos){
    if(pos == 1){
        Node<T>* n = cursor->next;
        cursor->next = n->next;
    }
    else{
        Node<T>* prev = cursor->next;
        for(int i = 2 ; i<pos ; i++){
            prev = prev->next;
        }
        Node<T> * curr = prev->next;
        prev->next = curr->next;
    }
    currnodes--;
}
template<typename T> int LinkedList<T> ::searchElem(int elem){
    int pos = -1;
    Node<T>* temporary = cursor->next;
    if(elem ==cursor->val) return currnodes;
    int currpos = 1;
    while(temporary!=cursor){
        if(temporary->val == elem){
            pos = currpos;
            break;
        }
        currpos++;
        temporary = temporary->next;
    }
    return pos;
}
template<typename T> int LinkedList<T> ::getSize(){
    return currnodes;
}
template<typename T> bool LinkedList<T> ::isEmpty(){
    if(currnodes == 0) return true;
    return false;
}
template<typename T> int LinkedList<T> ::printElemBeforePos(int pos){
    Node<T>* temporary = cursor->next;
    if(pos == 1){
        return cursor->val;
    }
    for(int i = 2 ; i<pos ; i++){
        temporary = temporary->next;
    }
    return temporary->val;
}
template<typename T> int LinkedList<T> ::printElemAfterPos(int pos){
    if(pos == currnodes){
        return cursor->next->val;
    }
    Node<T>* temporary = cursor->next;
    for(int i = 2 ; i<=pos+1 ; i++){
        temporary = temporary->next;
    }
    return temporary->val;
}
template<typename T> void LinkedList<T>::concatenate(LinkedList<T>& l){
    Node<T> * n = cursor->next;
    cursor->next = l.cursor->next;
    l.cursor->next = n; 
    cursor = l.cursor;
}


int main(){
    LinkedList <int> l,l1;
    int choice = 1;
    do{
        Node<int> * node = new Node<int>();
        int userChoice,pos,val,elem;
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
        cout << "13. Concatenate \n";
        cout << "14. Exit \n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , 1);
            break;
        case 2:
            cout << "enter the value of node : ";
            cin >> node->val;
            l.insert(node , l.currnodes+1);
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
            l.deleteNode(l.currnodes);
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
                node = new Node<int>(elem);
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