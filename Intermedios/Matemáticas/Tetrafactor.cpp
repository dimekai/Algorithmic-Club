#include <iostream>

using namespace std;

const int N = 6000000;
int is_tetra[N + 1];

void possible_tetrafactores(){
	for(int i = 1; i <= N; ++i){
		//cout << "i: " << i << "\n";
		for(int j = i; j <= N; j += i){
			//cout << "\t| j:" << j << " |";
			is_tetra[j]++;
			//cout << divs[j] << " multiplos |";
			//cout << "\n";
		}
		//cout << "\n";
	}
}

template<typename T>
T tetrafactor_is(T n){
	T count_tetras = 0;
	for(T i = 1; i <=N ; i++){
		if(is_tetra[i] == 4)	count_tetras++;
		if(count_tetras == n) 	return i;	
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	possible_tetrafactores();
	int n;
	cin >> n;
	cout << tetrafactor_is(n) << "\n";
}