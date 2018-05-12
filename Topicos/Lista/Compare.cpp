#include <iostream>
#include <string>
using namespace std;

int main(){
	string uno="", dos="";
	bool is = true;
	while(cin >> uno >> dos){
		is=true;
		if (uno.size()>dos.size() ||
			uno.size()<dos.size() ){
			cout << "distintos" << "\n";
			break;
		}
		
		for (int i = 0, j=0; i < uno.size(), j<dos.size(); i++,j++){
			cout << uno[i] << "---" << dos[j] << "\n";
				if (uno[i]==dos[j])
					is *= true;
				else
					is *= false;
		}


		if (is){
			cout << "iguales." << "\n";
		}else
			cout << "distintas." << "\n";
		uno="", dos="";
	}
}