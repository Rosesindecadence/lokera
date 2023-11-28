#include<iostream>

int main() {
	using namespace std;
	double edad_tierra, edad_planetas, dias_plan_solm = 88, dias_plan_solv = 225, dias_plan_solj = 4380, dias_plan_sols = 10767;

	cout << "Edad en la tierra: " ;
	cin >> edad_tierra;
	edad_planetas = (edad_tierra * 365) / dias_plan_solm;
	cout << "Edad en Mercurio: " << edad_planetas << endl;
	edad_planetas = (edad_tierra * 365) / dias_plan_solv;
	cout << "Edad en Venus: " << edad_planetas << endl;
	edad_planetas = (edad_tierra * 365) / dias_plan_solj;
	cout << "Edad en Jupiter: " << edad_planetas << endl;
	edad_planetas = (edad_tierra * 365) / dias_plan_sols;
	cout << "Edad en Saturno: " << edad_planetas << endl;
	return 0;
}