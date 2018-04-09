/*Pila
Metodos:
	- push(v)
	- pop()
	- top()
	- Empty()
Lista LIFO: Last In, First Out*/

/*Ejercicio de balanceo de paréntesis.*/


/*Balanceo de paréntesis, corchetes y llaves: ()[]{}*/
#include <iostream>
#include <string>
using namespace std;

bool isBalanced(string &sentence){
	Stack* paren = new Stack();

	for (auto c:sentence){
		switch(c){
			case '(':case'[':case'{':
				paren->push(c);
				break;
			case ')':
				if (!paren->isEmpty() && 
					paren->top()=='('){
					paren->pop();
				}else
					return false;
				break;
			case ']':
				if (!paren->isEmpty() && 
					paren->top()=='['){
					paren->pop();
				}else
					return false;
				break;
			case '}':
				if (!paren->isEmpty() && 
					paren->top()=='{'){
					paren->pop();
				}else
					return false;
				break;
		}//cierra switch.
	}//cierra for
	return paren->isEmpty();
}