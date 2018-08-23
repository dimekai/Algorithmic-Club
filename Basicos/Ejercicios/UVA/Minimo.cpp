#include <iostream>
using namespace std;

int main(){
	long t,a,b;
	cin >> t;
	while(t--){
		a=0;
		b=0;
		cin >> a >> b;
		if(a==b)
			cout << "=" << "\n";
		else if (a>b)
			cout << ">" << "\n";
		else
			cout << "<" << "\n";		
	}
	return 0;
}