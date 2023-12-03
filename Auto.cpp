#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Automovil {
private:
    std::string modelo;
    std::string color;
    std::string marca;
    std::string matricula;

public:
    Automovil(std::string mod = "", std::string col = "", std::string mar = "", std::string matr = "")
        : modelo(mod), color(col), marca(mar), matricula(matr) {}

    std::string getMarca() const {
        return marca;
    }

    std::string getMatricula() const {
        return matricula;
    }

    std::string getModelo() const {
        return modelo;
    }

    std::string getColor() const {
        return color;
    }

    void setMarca(std::string mar) {
        marca = mar;
    }
    void setMatricula(std::string matr) {
        matricula = matr;
    }

    void setModelo(std::string mod) {
        modelo = mod;
    }

    void setColor(std::string col) {
        color = col;
    }
};

void mostrarInformacion(const Automovil& autoMostrar) {
    std::cout << "Modelo: " << autoMostrar.getModelo() << std::endl;
    std::cout << "Color: " << autoMostrar.getColor() << std::endl;
    std::cout << "Marca: " << autoMostrar.getMarca() << std::endl;
    std::cout << "Matricula: " << autoMostrar.getMatricula() << std::endl;
}

int main() {
    std::vector<Automovil> autos;

    int opcion;

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Registrar coche" << std::endl;
        std::cout << "2. Buscar coche registrado" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            Automovil autoNuevo;
            std::string modelo, matricula, marca, color;

            std::cout << "Ingrese el modelo del coche: ";
            std::cin >> modelo;
            autoNuevo.setModelo(modelo);

            std::cout << "Ingrese la matricula del coche: ";
            std::cin >> matricula;

            std::cout << "Ingrese la marca del coche: ";
            std::cin >> marca;
            autoNuevo.setMarca(marca);

            std::cout << "Ingrese el color del coche: ";
            std::cin >> color;
            autoNuevo.setColor(color);

            autos.push_back(autoNuevo);
            break;
        }
        case 2: {
            if (!autos.empty()) {
                std::string modeloBuscar;
                std::cout << "Ingrese el modelo del coche a buscar: ";
                std::cin >> modeloBuscar;

                auto it = std::find_if(autos.begin(), autos.end(), [modeloBuscar](const Automovil& autoBuscar) {
                    return autoBuscar.getModelo() == modeloBuscar;
                    });

                if (it != autos.end()) {
                    std::cout << "Coche encontrado. Informacion:" << std::endl;
                    mostrarInformacion(*it);
                }
                else {
                    std::cout << "No se encontro ningún coche con ese modelo." << std::endl;
                }
            }
            else {
                std::cout << "No hay coches registrados." << std::endl;
            }
            break;
        }
        case 3:
            std::cout << "Saliendo." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida." << std::endl;
        }

    } while (opcion != 3);

    return 0;
}

