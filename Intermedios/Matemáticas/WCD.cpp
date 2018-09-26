#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<lli,lli> plli;
typedef vector<plli> vplli;

vi divisores(lli N){
	vi divisores;

	for(int i = 1; i <= sqrt(N); i++){
		if (N%i == 0){
		   divisores.push_back(i);
		   if (i*i != N) divisores.push_back(N/i);
		}
	}

	sort(divisores.begin(), divisores.end());

	return divisores;
}


lli verifyWCD(vplli pairs, vi factors){
	bool is = false;
	for(int j = 0; j < factors.size() ; j++){
		for(int i = 1; i < pairs.size() ; i++){

			//cout << "Pair: [" << pairs[i].first << "," <<pairs[i].second << "]\n";
			//cout << "fact: " << factors[j] << " ";

			if(pairs[i].first%factors[j] == 0 || 
		   	   pairs[i].second%factors[j] == 0 ){
		   	   //cout << "Si \n";
			   is += true;
		   	   continue;
			}else{ 
				//cout << "No \n";
		   		is = false;
		   		break;
		   	}
		}
		if(is)
			return j;
	}

	return -1;
}


int main(){
	int num;

	while(cin >> num){
			vplli pairs;
		for(int i=0; i < num ; i++){
			plli wcd;
			cin >> wcd.first >> wcd.second;
			pairs.push_back(wcd);
		}

		vi factors_a = divisores(pairs[0].first);
		vi factors_b = divisores(pairs[0].second);	

		/*
		cout << "factores a:";
		for(auto a: factors_a)
			cout << a << " ";

		cout << "\n";
		cout << "factores b:";
		for(auto b: factors_b)
			cout << b << " ";
		*/

		lli isA = verifyWCD(pairs, factors_a);
		lli isB = verifyWCD(pairs, factors_b);

		//cout << "isA: " << isA;
		//cout << "isB: " << isB;

		if( isA != -1)			cout << factors_a[isA];
		else if(isB != -1)		cout << factors_b[isB];
		else	 				cout << "-1";
		
	}
}