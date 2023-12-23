#include <iostream>
using namespace std;
class stck
{
private:
	int *arr = nullptr;
	int size, count;
	int top;

public:
	stck(int siz)
	{
		size = siz;
		top = -1;
		arr = new int[siz];
	}
	int   pop();
	void   push(int n);
	int   peek();
	void   display();
	bool   empty();
};

int  stck:: pop()
{
	if (arr == nullptr)
	{
		cout << "underflow\n";
		return -1;
	}

	return arr[top--];
}

void  stck:: push(int n)
{
	if (top == size - 1)
	{
			cout << "overflow\n";
	}
	else
	{
		arr[++top] = n;
	}
}

int  stck:: peek()
{
	if (top == -1)
	{
		cout << "stck is empty" << endl;
		return -1;
	}
	return arr[top];
}
void  stck:: display()
{
	if (top == -1)
	{
		cout << "empty" << endl;
	}
	for (int i = 0; i <= top; i++)
		cout << arr[i] << " ";

	cout << endl;
}
bool  stck:: empty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}
bool bracesmatching(string s);
int main()
{
	string s;
	cin>>s;
	bool re = bracesmatching(s);
	cout<<re;

	return 0;}
bool bracesmatching(string s)
{int len = s.length();
	stck braces(len);
	
	for(int i = 0;i<len;i++)
	{if((int)s[i]==41 || (int)s[i] == 125 || (int)s[i] == 93)
		{if(braces.empty())
			{return false;}
			
		else{
			int data= braces.pop();	
			int curr = (int)s[i];
		if(curr == 41&&data!=40)
		{return false;}
		if(curr == 125&&data!=123)
		{return false;}
		if(curr == 93&&data!=91)
		{return false;}
			
			}
		}
		if((int)s[i]==40 || (int)s[i] == 123 || (int)s[i] == 91)
		{int data1 = (int)s[i];
			braces.push(data1);
			}	
		}
		if(braces.empty())return true;
	return false;
	}

	