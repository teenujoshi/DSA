#include <iostream>
using namespace std;

class node
{public:
	int data;
    node *left;
    node *right;
    
};
 
class bst
{public:
	node*root = new node;
	node*trav = root;
	int level =0;
	bst()
	{}
	bst(int n)
	{root->data=n;
		root->left=NULL;
		root->right=NULL;
		}
	void changetrav();	
	void insert(int n);
	void inorder(node*temp);
	void preorder(node*temp);
	void postorder(node*temp);
	node* search(node*temp,int key);
	node* delet(node*,int key);
	node * minimumvalue(node*temp);
	node* predess(node*temp);
	node* successor(node*temp);
	void levelorder(node * temp);
	int height(node * temp);
	void printcurrentlevel(node *temp,int n);
		node* returnbefore(node *temp,int key);
	node* deletebymerging(node * temp,int key);	
	void leftrotate(node *temp)
	{node *temp2= temp->right;
node *temp3 = temp2->left;

temp2->left = temp;
temp->left =temp3;	
	}	
		
	};
	
void bst::changetrav()
{trav = root;
	}	
	
	void bst::insert(int value)
	{ node * p = root;
		node *prev = NULL;
		if(p==NULL)
		{p->data=value;
			p->left=NULL;
			p->left=NULL;
			}
	else{		
		while(p!=NULL)
		{prev = p;
			if(p->data==value)
			{   return;
				break;}
			else if(value <p->data)
			{p = p->left;
				}
			else{ p = p->right;
				}	
			
			}
			
		node *temp = new node;
		temp->left = NULL;
		temp->right = NULL;
		temp->data = value;
		if(value < prev->data)
		{prev->left = temp;
			}
			else{prev->right=temp;
				}
			}
		}
node* bst::search(node*temp,int key) // temp should be equal to root
{
	if(temp==NULL)
	{return NULL;
		}
	else if(temp->data==key)
	      return temp;
    else if(temp->data>key)
	      return search(temp->left,key);
	  else
	  {return search(temp->right,key);
		  }	
	}		
void bst::inorder(node*temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}
void bst::preorder(node*temp)
{
    if(temp==NULL)
    return;
    else{
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);}
    
}
void bst::postorder(node*temp)
{
    if(temp==NULL)
    return;
    else{
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";}
         
}
void bst::levelorder(node * temp)
{int h = height(temp);
	
	for(int i =1;i<=h;i++){
	printcurrentlevel(temp,i);
	cout<<endl;}
	}

void bst::printcurrentlevel(node *temp,int n)
{if(temp == NULL)return;
	if(n == 1)cout<<temp->data<<" ";
else if(n>1)
{
	printcurrentlevel(temp->left,n-1);
	printcurrentlevel(temp->right,n-1);
	}	
	}	
	
int bst::height(node * temp)
{if(temp == NULL)return 0;
	
	else{int leftheight = height(temp->left);
		int rightheight = height(temp->right);
		if(leftheight>rightheight)return (leftheight+1);
		else
		return (rightheight + 1);
		}
	}
node* bst::delet(node *temp,int key)
 {    
	 if(key<temp->data)
	 {temp->left = delet(temp->left,key); 
		 }
	else if(key>temp->data)
	{temp->right = delet(temp->right,key);
		}
	else{//no child
		if(temp->left==NULL&&temp->right==NULL)
		  {node * temp1 = temp->right;
			  delete(temp);
			  return temp1;
			  }
	   //one child		  
		else if(temp->right==NULL)
		{node * temp1 = temp->left;
			  delete(temp);
			  return temp1;
			}
		else if(temp->left ==NULL)
		{node * temp1  = temp->right;
			delete(temp);
			return temp1;
			}	
			//two child
		node* temp1=minimumvalue(temp->right);
		//cout<<temp1->data<<endl;
		temp->data=temp1->data;
		temp->right = delet(temp->right,temp1->data);		  
			  
			  
		}return temp;		 
	
}
node* bst::minimumvalue(node*temp){
	node*curr=temp;
	while(curr&&curr->left!=NULL)
	{curr = curr->left;
		
		}return curr;
	}
node *bst::predess(node* temp){
	if(temp->right==NULL&&temp->left==NULL)
	{node *temp2 = returnbefore(trav,temp->data); 
	
	    if(temp2->data<temp->data){changetrav();
	return temp2;}
return temp;
	}
	
	node*current = temp;
	if(current!=NULL){
	current = current->left;}
	while(current && current->right!=NULL)
	current = current->right;

	return current;
	}
	node* bst::returnbefore(node *temp,int key){
	 if(temp->right->data==key || temp->left->data == key)
	      return temp;
    else if(temp->data>key)
	      return returnbefore(temp->left,key);
	  else
	  {return returnbefore(temp->right,key);
		  }
		}
node* bst::successor(node*temp){
	if(temp->right==NULL&&temp->left==NULL)
	{node *temp2 = returnbefore(trav,temp->data); 
	
	    if(temp2->data>temp->data){changetrav();
	return temp2;}
	else if(temp->data<root->data)
	return root;
	
	return temp;
	}
		node*current = temp;
	if(current!=NULL){
	current = current->right;}
	while(current && current->left!=NULL)
	current = current->left;
	
	return current;
	}
node* bst::deletebymerging(node*temp,int key)
{
  if(key<temp->data)
	 {temp->left = delet(temp->left,key); 
		 }
	else if(key>temp->data)
	{temp->right = delet(temp->right,key);
		}
		else{
 
    //no child 
      if(temp->left==NULL && temp->right == NULL)
      delete(temp);
      // one child
      else if(temp->left == NULL)
      {node *temp1 = temp->right;
      delete(temp);
      return temp1;}
      
      else if(temp->right == NULL)
      {node *temp1 = temp->left;
      delete(temp);
      return temp1;
          
      }
      else{
     
      if(key!=root->data)
     { changetrav();
      node*temp1 = returnbefore(trav,key);
      temp1->right = temp->right;
       node *temp3 = minimumvalue(temp->right);
      temp3->left = temp->left;
      delete(temp);
      
      delete(temp);}
      
      else
      {node*temp1 = temp->right;
      node *temp3 = minimumvalue(temp->right);
      node*temp4 = temp->left;
     
      root = temp1;
      temp3->left = temp4;
         delete(temp);  
      }
          
      }
		}
  
    return temp;  
  }

int main()
{bst bt(5);

	node * temp = new node;

	node* temp2 = new node;
	//bt.insert
	int value;int choice;
	do{ 
		cout<<"1.insert"<<endl;
		//cout<<"2.delete"<<endl;
		cout<<"2.search"<<endl;
		cout<<"3.preorder"<<endl;
		cout<<"4.postorder"<<endl;
		cout<<"5.inorder"<<endl;
		cout<<"6.level order"<<endl;
		cout<<"7.predecessor"<<endl;
		cout<<"8.successor"<<endl;
		cout<<"9.delete by copy"<<endl;
		cout<<"10.delete by merging"<<endl;
		cout<<"0. to exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		
		switch(choice)
		{case 1:
			cout<<"enter value"<<endl;
			cin>>value;
			bt.insert(value);
			cout<<endl;
			break;
		case 2:
		   cout<<"Enter value to search"<<endl;
		   cin>>value;
		   bt.changetrav();
		   
		   temp = bt.search(bt.trav,value);
	if(temp==NULL)
	{
		cout<<"not found";}
	else{
		cout<<"found";}
		 bt.changetrav();
		    cout<<endl;
		    break;
		    
		 case 3:

		  temp = bt.root;
		   bt.preorder(temp);
		   cout<<endl;  
		   break; 
		 case 4:
		   bt.changetrav();
		   temp = bt.root;
		   bt.postorder(temp);
		   cout<<endl;  
		   break; 
		 case 5:
		   bt.changetrav();
		   temp = bt.root;
		   bt.inorder(temp);
		   cout<<endl; 
		   break; 
		 case 6:
		   bt.changetrav();
		   temp = bt.root;
		   bt.levelorder(temp);
		   cout<<endl; 
		   break; 
		  case 7:
		  cout<<"enter vakue to find for predessesor"<<endl;
		  cin>>value;
		   bt.changetrav();
		   temp = bt.search(bt.trav,value);
		  bt.changetrav();
		  temp2 = bt.predess(temp);
		  cout<<endl<<temp2->data<<endl;
		  break; 
		  case 8:
		  cout<<"enter vakue to find for successor"<<endl;
		  cin>>value;
		   bt.changetrav();
		   temp = bt.search(bt.trav,value);
		  bt.changetrav();
		 temp2 = bt.successor(temp);
		 cout<<endl<<temp2->data<<endl;
		  break; 
		  case 9:
		  cout<<"enter vakue to delete"<<endl;
		  cin>>value;
		  bt.changetrav();
		  bt.delet(bt.trav,value);
		  break; 
		  case 10:
		  cout<<"enter vakue to delete"<<endl;
		  cin>>value;
		  bt.changetrav();
		  bt.deletebymerging(bt.trav,value);
		  

		  break; 
		    
		   	
			}
		}while(choice!=0);
		
		
		return 0;
		
		
		}				

/*void bst::levelorder(node * temp)
{if(temp == NULL)
	{
	return ;}
 else if(temp->left == NULL&& temp->right == NULL)
    {cout<<temp->data<<" ";
    return;}
 
   levelorder(temp->left);   	
   levelorder(temp->right);   	
	}
	* 
	* node* bst::delet(node *temp,int key)
 {   node* pre;
     
	 if(key<temp->data)
	 {temp->left = delet(temp->left,key); 
		 }
	else if(key>temp->data)
	{temp->right = delet(temp->right,key);
		}
		else{if(temp==NULL)return NULL; 
     else if(temp->left==NULL&&temp->right==NULL)
          {delete (temp);
          return NULL;}
		    pre = predess(temp->right);
		    temp->data = pre->data;
		    temp->right = delet(temp->right,pre->data);
		}
		return temp;
     
}
if(key<temp->data)
  temp->left = deletebymerging(temp->left,key);
  else if(key>temp->data)
  temp->right = deletebymerging(temp->right,key);*/	
  
   /*
                                                                5
                                                               / \
                                                               4  7
                                                                  /\
                                                                  6  8*/	
		
			
			

