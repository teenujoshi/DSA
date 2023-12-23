//ll representation of stack

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=NULL;
    }
};
class Stack{
    public:
    node* top;
    void push(int x){
        node* n=new node(x);
        n->next =NULL;
        if(top==NULL){
            top=n;
            return;
        }
        n->next=top;       
        top=n;

    }
    void pop(){
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        node* todelete=top;
        top=top->next;
        delete todelete;
    }
    int peek(){
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        return false;
    }
    int size(){
        int count=0;
        for(node* temp=top;temp->next!=NULL;temp=temp->next){
            count++;
        }
        return count;
    }
    void display(){
        cout<<"\n\n";
        for(node* temp=top;temp->next->next!=NULL;temp=temp->next){
            cout<<temp->data<<" ";
        }
    }

};
int main()
{
    Stack s;
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(8);
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.display();
    cout<<s.size()<<endl;
     return 0;
}

















//====double ended queue
// #include<iostream>
// using namespace std;
// class node{
//     public:
//     int data;
//     node* next;

//     node(int value){
//         data=value;
//         next=NULL;
//     }
// };
// class queue{
//     public:
//     node* front;
//     node* back;

//     void insertAtEnd(int x){
//         node* n=new node(x);
//         n->next=NULL;
//         if(front==NULL){
//             back=n;
//             front=n;
//             return;
//         }
//         back->next=n;
//         back=n;
//     }
//     void insertAtFront(int x){
//         node* n=new node(x);
//         if(front==NULL){
//             back=n;
//             front=n;
//             return;
//         }
//         n->next=front;
//         front=n;
//     }
//     void dltAtStart(){
//         if(front==NULL){
//             cout<<"Queue underflow"<<endl;
//             return;
//         }
//         node* todelete=front;
//         front=front->next;
//         delete todelete;
//     }
//     void dltAtEnd(){
//         if(front==NULL){
//             cout<<"Queue underflow"<<endl;
//             return;
//         }
        
//         for(node* temp=front;temp->next!=NULL;temp=temp->next){
//             if(temp->next->next == NULL){
//                 temp->next=NULL;
//                 back=temp;
//                 break;
//             }
       
//         }
//         // node* todelete=back;

//         // delete todelete;
//     }
//     int peek(){
//         if(front==NULL){
//             cout<<"Queue underflow"<<endl;
//             return -1;
//         }
//         return front->data;
//     }
//     bool empty(){
//         if(front==NULL){
//             return true;
//         }
//         return false;
//     }
//     // void display(){

//     // }
// };
// int main()
// {
//     queue q;
//     // int x,y;
//     // cout<<"Enter the number of elements to insert in the queue"<<endl;
//     // cin>>x;
//     // cout<<"Enter the elements"<<endl;
//     // for(int i=0;i<x;i++){
//     //     cin>>y;
//     //     q.insertAtEnd(y);
//     // }
//     q.insertAtEnd(1);
//     q.insertAtEnd(2);
//     q.insertAtEnd(3);
//     q.insertAtEnd(4);
//     cout<<q.peek()<<endl;
//     // q.dltAtStart();
//     // cout<<q.peek()<<endl;
//     // cout<<q.empty()<<endl;
//      return 0;
// }



//===============GCD ITERATION
// #include <iostream>
// using namespace std;
// int gcd(int a, int b)
// {
//     int result = min(a, b); 
//     while (result > 0) {
//         if (a % result == 0 && b % result == 0) {
//             break;
//         }
//         result--;
//     }
//     return result; 
// }
// int main(){
//     int a,b;
//     cin>>a;
//     cin>>b;
//     cout<<gcd(a,b);
//     return 0;
// }









// //===============GCD RECURSION
// #include <iostream>
// using namespace std;

// int gcd(int a,int b){
//     if(a==0||b==0){
//         return 0;
//     }
//     else if(a==b){
//         return a;
//     }
//     else if(a>b){
//         return gcd(a-b,b);
//     }
//     else
//         return gcd(a,b-a);
// }
// int main(){
//     int a,b;
//     cin>>a;
//     cin>>b;
//     cout<<gcd(a,b);
//     return 0;
// }










// //=============FIBONACCI ITERATION
// #include <iostream>
// using namespace std;

// int main(){
//     int num;
//     cout<<"Enter the number: "<<endl;
//     cin>>num;

//     int f1=0,f2=1;
//     cout<<"Fibonacci series is: "<<f1<<" "<<f2;
//     for(int i=2;i<num;i++){
//         int f=f1+f2;
//         f1=f2;
//         f2=f;
//         cout<<" "<<f;
//     }
//     cout<<endl;
// }














// //==============FACTORIAL

// #include <iostream>
// using namespace std;

// int IterFactorial(int num){
//     int factorial=1;
//     for(int i=1;i<=num;i++){
//         factorial=factorial*i;
//     }
//     return factorial;
// }
// int recurFactorial(int num){
//     if(num==0||num==1){
//         return 1;
//     }
//     else if(num==2){
//         return 2;
//     }
//     else
//         return num*recurFactorial(num-1);

// }
// int main(){
//     cout<<"ENTER NUMBER"<<endl;
//     int num;
//     cin>>num;

//     // cout<<IterFactorial(num);
//     cout<<recurFactorial(num);
//     return 0;
// }













// //======================SELECTION SORT

// #include <iostream>
// using namespace std;

// void selectionSort(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 int temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     selectionSort(arr,n);
//     return 0;
// }
















//==================INSERTION SORT

// #include <iostream>
// using namespace std;

// void insertionSort(int arr[],int n){
//     for(int i=1;i<n;i++){
//         int current=arr[i];
//         int j=i-1;
//         while(arr[j]>current&&j>=0){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=current;
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     insertionSort(arr,n);
// }














//===============BUBBLE SORT
// #include <iostream>
// using namespace std;

// void bubblesort(int arr[],int n){
//     // int n;
//     // int arr[n];
//     int counter=1;
//     while(counter<n){
//         for(int i=0;i<n-counter;i++){
//             if(arr[i]>arr[i+1]){
//                 int temp=arr[i];
//                 arr[i]=arr[i+1];
//                 arr[i+1]=temp;
//             }
//         }
//         counter++;
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     bubblesort(arr,n);
// }










//================FIBONACCI

// #include <iostream>
// using namespace std;

// int fibonacci(int n){
//     if(n==0){
//         return 0;
//     }
//     else if(n==1||n==2){
//         return 1;
//     }
//     else 
//         return (fibonacci(n-1)+fibonacci(n-2));
// }
// int main(){
//     int n;
//     cout<<"enter the number"<<endl;
//     cin>>n;
//     cout<<"Fibonacci series is: ";
//     for(int i=0;i<n;i++){
//         cout<<fibonacci(i)<<" ";
//     }
    
//     return 0;
// }








//================QUEUE LL implementation

// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;

//     node(int value){
//         data=value;
//         next=NULL;
//     }
// };
// class Queue{
//     public:
//     node* front;
//     node* back;

//     Queue(){
//         front=NULL;
//         back=NULL;
//     }

//     void push(int x){
//         node* n=new node(x);
//         if(front==NULL){
//             front=n;
//             back=n;
//             return;
//         }
//         back->next=n;
//         back=n;
//     }
//     void pop(){
//         if(front==NULL){
//             cout<<"Queue underflow"<<endl;
//             return;
//         }
//         node* todelete=front;
//         front=front->next;

//         delete todelete;
//     }
//     int peek(){
//         if(front==NULL){
//             cout<<"No elements in the queue"<<endl;
//             return -1;
//         }
//         return front->data;
//     }
//     bool empty(){
//         if(front==NULL){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
    
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.empty();

//     return 0;
// }









//==============QUEUE Array implementation


// #include <iostream>
// using namespace std;
// #define n 50

//  class Queue{
//     public:
//         int* arr;
//         int front;
//         int back;

//         Queue(){
//             arr=new int[n];
//             front=-1;
//             back=-1;
//         }

//         void push(int x){
//             if(back==n-1){
//                 cout<<"Queue overflow"<<endl;
//                 return;
//             }
//             back++;
//             arr[back]=x;

//             if(front==-1){
//                 front++;
//             }
//         }
//         void pop(){
//             if(front==-1||front>back){
//                 cout<<"NO elements in queue"<<endl;
//                 return;
//             }
//             front++;
//         }
//         int peek(){
//             if(front==-1||front>back){
//                 cout<<"no elements"<<endl;
//                 return -1;
//             }
//             return arr[front];
//         }
//         bool empty(){
//             if(front==-1||front>back){
//                 return true;
//             }
//             return false;
//         }
//  };
//  int main(){
//     Queue q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.empty();

    // return 0;
    

//  }


















//===============SLL

//===============SLL

// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;
    
//     node(){
//         data=0;
//         next=NULL;
//     }
//     node(int value){
//         data=value;
//         next=NULL;
//     }
// };
// class SLL{
//     public:
//     node* tail;
//     node* head;
//     int currnode=0;
// void insertAtTail(node* &head,int val){
//     node* n=new node(val);

//     if(head==NULL){
//         head=n;
//         return;
//     }
//     node* temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     temp->next=n;
// }
// void insertAtHead(node* &head,int val){
//     node* n= new node(val);
//     n->next=head;
//     head=n;
// }
// bool search(node* head,int key){
//     node* temp=head;
//     while(temp->next!=NULL){
//         if(temp->data==key){
//             return true;
//         }
//         temp=temp->next;
//     }
//     return false;
// }

// void deleteAtHead(node* &head){
//     node* todelete=head;
//     head=head->next;

//     delete todelete;
// }
// void deletion(node* &head,int val){
//     if(head==NULL){
        // return;
//     }
//     if(head->next==NULL){
//         deleteAtHead(head);
//         return;
//     }
//     node* temp=head;
//     while(temp->next->data!=val){
//         temp=temp->next;
//     }
//     node* todelete=temp->next;
//     temp->next=temp->next->next;

//     delete todelete;
// }
// void display(node* head){
//     node* temp=head;
//     while(temp!=NULL){
//         cout<<temp->data<<" -> ";
//         temp=temp->next;
//     }
//     cout<<"NULL"<<endl;
// }
// node* reverse(node* &head){
//     if(head==NULL||head->next==NULL){
//         return head;
//     }
//     node* newhead=reverse(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return newhead;
// }
// node* reverseIter(node* &head){
//     node* prevptr=NULL;
//     node* currptr=head;
//     node* nextptr;
//     while(currptr!=NULL){
//         nextptr=currptr->next;
//         currptr->next=prevptr;

//         prevptr=currptr;
//         currptr=nextptr;
//     }
//     return prevptr;
// }
// void concatenate(SLL &l1){
//     tail->next=l1.head;
//     l1.tail->next=NULL;
//     tail=l1.tail;
//     currnode+=l1.currnode;
// }
// };
// int main(){
    
//     SLL s,l1;
    
//     node* head=NULL;
//     s.insertAtTail(head,16);
//     s.insertAtTail(head,25);
//     s.insertAtTail(head,32);
//     s.display(head);
//     s.insertAtHead(head,4);
//     s.display(head);
//     // cout<<"\n"<<s.search(head,4)<<endl;
//     // s.deleteAtHead(head);
//     // s.display(head);
//     // s.deletion(head,32);
//     // s.display(head);
//     // s.deletion(head,25);
//     // s.display(head);

//     // node* newhead=s.reverse(head);
//     // s.display(newhead);
//     // node* newhead=s.reverseIter(head);
//     // s.display(newhead);
//     cout<<"\n";
//     l1.insertAtTail(head,20);
//     l1.insertAtTail(head,25);
//     l1.insertAtTail(head,32);
//     l1.display(head);
    
//     s.concatenate(l1);
//     l1.display(head);
//     return 0;

// }
























///=============STACK

// #include <iostream>
// using namespace std;
// #define n 100
// class Stack{

//     public:
//         int *arr;
//         int top;
//         Stack(){
//             arr=new int[n];
//             top=-1;
//         }
//         void push(int x){
//             if(top==n-1){
//                 cout<<"OverFlow"<<endl;
//             }
//             else
//                 arr[++top]=x;

//         }
//         void pop(){
//             if(top==-1){
//                 cout<<"Underflow"<<endl;
//             }
//             else 
//                 int x=arr[top--];
//         }
//         int peek(){
//             if(top==-1){
//                 cout<<"The stack is empty"<<endl;
//             }
//             else
//                 return arr[top];
//         }
//         void isEmpty(){
//             if(top==-1){
//                 cout<<"\nStack is empty"<<endl;
//             }
//             else
//                 cout<<"\nStack is not empty"<<endl;
//         }
//         int size(){
//             return top+1;
//         }
//         void display(){
//             for(int i=top;i>=0;i--){
//                 cout<<arr[i]<<" ";
//             }
//         }
//         void rolling(int noOfTimes){
//             for(int i=0;i<noOfTimes;i++){
//                 int topTemp=0;
//                 int temp;
//                 temp=arr[0];
//                 for(int j=0;j<size()-1;j++){
//                     arr[topTemp]=arr[topTemp+1];
//                     top++;
//                 }
//                 arr[top]=temp;
//             }
//         }
// };
// int main(){
//     Stack s;
//     int x,y;
//     cout<<"Number of elements to push in the stack"<<endl;
//     cin>>x;
//     cout<<"Value of elements to push in the stack"<<endl;
//     for(int i=0;i<x;i++){
//        cin>>y;
//        s.push(y);
//     }
//     cout<<"\nTop element is: "<<s.peek();
//     s.pop();
//     cout<<"\nAfter pop the top element is: "<<s.peek()<<endl;
//     s.isEmpty();
//     s.display();
//     cout<<"\n"<<s.size();
//     s.rolling(3);
//     s.display();

//     return 0;

// }























// #include <iostream>
// #include <malloc.h>
// using namespace std;

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;
// };

// struct node* createNode(int data){
//     struct node* n;
//     n=(struct node*)malloc(sizeof(struct node));
//     n->data=data;
//     n->left=NULL;
//     n->right=NULL;
//     return n;
// }
// void preOrder(struct node* root){
//     if(root!=NULL){
//         printf("%d ",root->data);
//         preOrder(root->left);
//         preOrder(root->right);
//     }
// }
// void postOrder(struct node* root){
//     if(root!=NULL){
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%d ",root->data);
//     }

// }
// void inOrder(struct node* root){
//     if(root!=NULL){
//         inOrder(root->left);
//         printf("%d ",root->data);
//         inOrder(root->right);
//     }
// }
// //Node* search(node* root,int key){}
// int main(){
//     // cout<<"Enter the nodes to insert in the tree"<<endl;
//     // for(int i=0;i<6;i++){
//     //     struct node* p = createNode(i);
//     //     cin >> p;
//     // }
//     // cout<<"Display the tree"<<endl;
//     // for(int i=0;i<6;i++){
//     //     struct node* p = createNode(i);
//     //     cout<< p;
//     // }
//     struct node* p=createNode(4);
//     struct node* p1=createNode(1);
//     struct node* p2=createNode(5);
//     struct node* p3=createNode(2);
//     struct node* p4=createNode(6);
//     inOrder(p);
//     preOrder(p);
//     postOrder(p);

//     return 0;
// }