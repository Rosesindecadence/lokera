#include <iostream>
#include <cmath>

int main() {
    double w, h, imc;

    using namespace std;

    cout << "Ingresa peso (KG): ";
    cin >> w;
    cout << "Ingresa altura (M): ";
    cin >> h;

    imc = w / pow(h, 2);

    cout << "Su IMC es: " << imc << endl;

    return 0;
}
