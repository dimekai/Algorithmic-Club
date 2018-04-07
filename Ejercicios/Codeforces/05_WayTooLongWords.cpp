#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	//number of words
	int n;
	//Read number
	cin >> n;
	int leng;


	string words[n];

	leng = sizeof(words) / sizeof(words[0]) ;
	cout << "Cadena" << leng;

	for (int i = 0; i < sizeof(words) / sizeof(words[0]) ;; ++i)
	{
		cin >> words[i];
	}
	
	for (int i = 0; i < sizeof(words) / sizeof(words[0]) ;; ++i)
	{
		cout << words[i];
	}
}