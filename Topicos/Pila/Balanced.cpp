#include <iostream>
#include <string>
#include <stack> 
using namespace std;

bool isBalanced(string &sentence){
	//stack* paren = new stack();
	stack<char> paren;
	for (auto c:sentence){
		switch(c){
			case '(':case'[':case'{':
				paren.push(c);
				break;
			case ')':
				if (!paren.empty() && 
					paren.top()=='('){
					paren.pop();
				}else
					return false;
				break;
			case ']':
				if (!paren.empty() && 
					paren.top()=='['){
					paren.pop();
				}else
					return false;
				break;
			case '}':
				if (!paren.empty() && 
					paren.top()=='{'){
					paren.pop();
				}else
					return false;
				break;
		}//cierra switch.
	}//cierra for
	return paren.empty();
}


int main(){
	int n;
	cin >> n;
	string sequence="";
	for (int i = 0; i < n; i++){
		sequence="";
		cin >> sequence;
		if (isBalanced(sequence))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";			
	}
}