//============================================================================
// Name        : thermodynamics.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



double lawNewtonRichman(double T, double alfa, double dt, double R1, double R2, double lamb, double Cp) {
	return 1;
}

double heatConduction(double Tminus, double Tzero, double Tplus, double p, double dt) {
	return 1;
}







int main() {

// Enter variables

	// Enter R1, R2. (m)
	double r1, r2;
	cin >> r1 >> r2;

	// Enter dt (sec)
	double dt;
	cin >> dt;

	// Enter p (kg/m^3)
	double p;
	cin >> p;

	// Enter Cp (J/kg)
	double Cp;
	cin >> Cp;

	// Enter lamb (W/(m * K))
	double lamb;
	cin >> lamb;

	// Enter n
	size_t n;
	cin >> n;

	// Enter Ti (K) n times
	vector<double> beforeVectorT;
	vector<double> resultVectorT;

	for(size_t i = 0; i < n; ++i) {
		double var;
		cin >> var;
		beforeVectorT.push_back(var);
	}

	// Enter alfa1, alfa2 (W/(m^2 * K))
	double alfa1, alfa2;
	cin >> alfa1 >> alfa2;

	// Enter T1, T2 (K)
	double T1, T2;
	cin >> T1 >> T2;

// Main function realisation

	double forT1 = lawNewtonRichman(T1, alfa1, dt, r1, r2, lamb, Cp);
	double forT2 = lawNewtonRichman(T2, alfa2, dt, r1, r2, lamb, Cp);

	resultVectorT.push_back(forT1);


	for(size_t i = 1; i < n - 1; ++i) {
		if(i == 1) {
			resultVectorT.push_back(heatConduction(forT1, beforeVectorT[i], beforeVectorT[i+1], p, dt));
		} else if(i == n-2) {
			resultVectorT.push_back(heatConduction(beforeVectorT[i-1], beforeVectorT[i], forT2, p, dt));
		} else {
			resultVectorT.push_back(heatConduction(beforeVectorT[i-1], beforeVectorT[i], beforeVectorT[i+1], p, dt));
		}
	}

	resultVectorT.push_back(forT2);




	return 0;
}
