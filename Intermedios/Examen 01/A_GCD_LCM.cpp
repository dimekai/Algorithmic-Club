#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> plii;

/*data.first -> G
  data.second -> L*/

lli GCD(lli a, lli b){
	return (b)?GCD(b,a%b):a;
}

lli MCM(lli a, lli b,lli GCD){
	return (abs(a*b)/GCD);
}

int main(){
	short cases;
	cin >> cases;
	while(cases--){
		plii data;
		cin >> data.first >> data.second;

		lli gcd = GCD(data.first, data.second);
		lli mcm = MCM(data.first, data.second, gcd);
		
		/*cout << "GCD: "<< GCD(data.first, data.second);
		cout << "MCM: "<< MCM(data.first, data.second);*/

		if((gcd != data.first) && (mcm != data.second))
			cout << "-1";
		else
			cout << gcd <<" "<< mcm;

		cout << "\n";
	}
}