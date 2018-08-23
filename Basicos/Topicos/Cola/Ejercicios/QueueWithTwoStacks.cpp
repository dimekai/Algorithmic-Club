#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> guarda, front;
	int q;
	while(cin>>q){
		while(q--){
			short type;
			cin >> type;
			if (type == 1){
				int x;
				cin >> x;
				guarda.push(x);
			}else {
				if (front.empty()){
					while(!guarda.empty()){ /*Hacemos la pila una cola*/
						front.push(guarda.top()); /*Esta hasta arriba le primero en llegar*/
						guarda.pop();
					}
				}
				if(!front.empty()){ /*Imprime/Saca los datos como fueron llegando */
					if (type==2)
						front.pop();
					if (type==3)
						cout << front.top() << "\n";
				}
			}
		}//cierra las q-ésimas queries
	}//cierra while que lee a 'q'
}