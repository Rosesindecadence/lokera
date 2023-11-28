#include <iostream>
#include <cmath>

int main() {
    double A, B, C;
    double discriminant, x1, x2;

    std::cout << "Ingrese el coeficiente A: ";
    std::cin >> A;
    std::cout << "Ingrese el coeficiente B: ";
    std::cin >> B;
    std::cout << "Ingrese el coeficiente C: ";
    std::cin >> C;

    discriminant = B * B - 4 * A * C;

    if (discriminant > 0) {
        x1 = (-B + std::sqrt(discriminant)) / (2 * A);
        x2 = (-B - std::sqrt(discriminant)) / (2 * A);
        std::cout << "Las soluciones son: x1 = " << x1 << " y x2 = " << x2 << std::endl;
    }
    else if (discriminant == 0) {
        x1 = -B / (2 * A);
        std::cout << "La solución única es: x = " << x1 << std::endl;
    }
    else {
        std::cout << "No hay soluciones reales para esta ecuación cuadrática." << std::endl;
    }

    return 0;
}
