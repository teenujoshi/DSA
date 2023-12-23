#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int precedence(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string infixToPostfix(string s) {

	stack<char> st;
	string ans = ""

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			ans += c;

		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(')
			{
				ans += st.top();
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	return ans;
}

string infixToPrefix(string s) {
   string p;
   reverse(s.begin(), s.end());
   string::iterator c;

   for(c = s.begin(); c != s.end(); c++) {
      if(*c == '(')
         *c = ')';
      else if(*c == ')')
         *c = '(';
   }

   p = infixToPostfix(s);
   reverse(p.begin(), p.end());
   return p;
}


int main() {
	string s;
	string p;
	cout<<"Enter Infix String: ";
	cin>>s;
	cout<<"Postfix String: "<<infixToPostfix(s)<<endl;;
	cout<<"Prefix String: "<<infixToPrefix(s);
	return 0;
}
