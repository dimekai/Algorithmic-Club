#include <iostream>
#include <vector>

using namespace std;
const int max_months=101;

int main(){
	int num_deps,months,paid_in;
	float down_py, loan;

	while(cin >> months >> down_py >> loan >> num_deps){
		if (months>0 && months<max_months)
		{
			vector<float> deprec(months,0);
			float mens=0, price=0;

			for (int i = 0; i < num_deps; i++){
				mens=0, price=0;
				cin >> mens >> price;
				for (int j = mens; j < deprec.size(); j++)
					deprec[j] = price;
			}
			
			float monthly, value_act, debt;

			monthly = loan/months;  		/*mensualidad*/
			value_act = (loan+down_py)*(1-deprec[0]);	/*enganch*/
			debt = loan;					/*deuda total*/
			paid_in=0;			/*Cantidad de meses que ha pagado hasta liquidar*/
			
			while(value_act < debt){
				paid_in++;
				debt -= monthly;
				value_act = value_act*(1-deprec[paid_in]);
			}

			cout << paid_in << " month";
			if (paid_in!=1)
				cout << "s";
			cout << "\n";
		}else break;
	}
	return 0;
}