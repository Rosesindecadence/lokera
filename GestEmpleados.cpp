#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::string CONTRASENA_CORRECTA = "Techno2023";

class Empleado {
private:
    std::string nombre;
    std::string apellido;
    std::string id;
    double salarioBase;
    double bonos;
    double deducciones;

public:
    Empleado(std::string nomb = "", std::string apell = "", std::string empId = "", double salBase = 0.0, double bon = 0.0, double deduc = 0.0)
        : nombre(nomb), apellido(apell), id(empId), salarioBase(salBase), bonos(bon), deducciones(deduc) {}

    std::string getNombre() const {
        return nombre;
    }

    std::string getApellido() const {
        return apellido;
    }

    std::string getId() const {
        return id;
    }

    double getSalarioBase() const {
        return salarioBase;
    }

    double getBonos() const {
        return bonos;
    }

    double getDeducciones() const {
        return deducciones;
    }

    void setNombre(std::string nomb) {
        nombre = nomb;
    }

    void setApellido(std::string apell) {
        apellido = apell;
    }

    void setId(std::string empId) {
        id = empId;
    }

    void setSalarioBase(double salBase) {
        salarioBase = salBase;
    }

    void setBonos(double bon) {
        bonos = bon;
    }

    void setDeducciones(double deduc) {
        deducciones = deduc;
    }
};

void mostrarInformacion(const Empleado& empleadoMostrar) {
    std::cout << "Nombre: " << empleadoMostrar.getNombre() << " " << empleadoMostrar.getApellido() << std::endl;
    std::cout << "ID: " << empleadoMostrar.getId() << std::endl;
    std::cout << "Salario Base: $" << empleadoMostrar.getSalarioBase() << std::endl;
    std::cout << "Bonos: $" << empleadoMostrar.getBonos() << std::endl;
    std::cout << "Deducciones: $" << empleadoMostrar.getDeducciones() << std::endl;
}

int main() {
    std::string contrasena;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> contrasena;

    if (contrasena != CONTRASENA_CORRECTA) {
        std::cout << "Contraseña incorrecta. Saliendo." << std::endl;
        return 1; 
    }

    std::vector<Empleado> empleados;

    int opcion;

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Agregar nuevo empleado" << std::endl;
        std::cout << "2. Consultar empleado" << std::endl;
        std::cout << "3. Modificar empleado" << std::endl;
        std::cout << "4. Eliminar empleado" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            Empleado nuevoEmpleado;
            std::string nombre, apellido, id;
            double salarioBase, bonos, deducciones;

            std::cout << "Ingrese el nombre del empleado: ";
            std::cin >> nombre;
            nuevoEmpleado.setNombre(nombre);

            std::cout << "Ingrese el apellido del empleado: ";
            std::cin >> apellido;
            nuevoEmpleado.setApellido(apellido);

            std::cout << "Ingrese el ID del empleado: ";
            std::cin >> id;
            nuevoEmpleado.setId(id);

            std::cout << "Ingrese el salario base del empleado: $";
            std::cin >> salarioBase;
            nuevoEmpleado.setSalarioBase(salarioBase);

            std::cout << "Ingrese los bonos del empleado: $";
            std::cin >> bonos;
            nuevoEmpleado.setBonos(bonos);

            std::cout << "Ingrese las deducciones del empleado: $";
            std::cin >> deducciones;
            nuevoEmpleado.setDeducciones(deducciones);

            empleados.push_back(nuevoEmpleado);
            break;
        }
        case 2: {
            if (!empleados.empty()) {
                std::string idBuscar;
                std::cout << "Ingrese el ID del empleado a consultar: ";
                std::cin >> idBuscar;

                auto it = std::find_if(empleados.begin(), empleados.end(), [idBuscar](const Empleado& empleadoBuscar) {
                    return empleadoBuscar.getId() == idBuscar;
                    });

                if (it != empleados.end()) {
                    std::cout << "Empleado encontrado. Informacion:" << std::endl;
                    mostrarInformacion(*it);
                }
                else {
                    std::cout << "No se encontro ningún empleado con ese ID." << std::endl;
                }
            }
            else {
                std::cout << "No hay empleados registrados." << std::endl;
            }
            break;
        }
        case 3: {
            if (!empleados.empty()) {
                std::string idModificar;
                std::cout << "Ingrese el ID del empleado a modificar: ";
                std::cin >> idModificar;

                auto it = std::find_if(empleados.begin(), empleados.end(), [idModificar](const Empleado& empleadoModificar) {
                    return empleadoModificar.getId() == idModificar;
                    });

                if (it != empleados.end()) {
                    std::string nombre, apellido, id;
                    double salarioBase, bonos, deducciones;

                    std::cout << "Ingrese el nuevo nombre del empleado: ";
                    std::cin >> nombre;
                    it->setNombre(nombre);

                    std::cout << "Ingrese el nuevo apellido del empleado: ";
                    std::cin >> apellido;
                    it->setApellido(apellido);

                    std::cout << "Ingrese el nuevo ID del empleado: ";
                    std::cin >> id;
                    it->setId(id);

                    std::cout << "Ingrese el nuevo salario base del empleado: $";
                    std::cin >> salarioBase;
                    it->setSalarioBase(salarioBase);

                    std::cout << "Ingrese los nuevos bonos del empleado: $";
                    std::cin >> bonos;
                    it->setBonos(bonos);

                    std::cout << "Ingrese las nuevas deducciones del empleado: $";
                    std::cin >> deducciones;
                    it->setDeducciones(deducciones);

                    std::cout << "Empleado modificado correctamente." << std::endl;
                }
                else {
                    std::cout << "No se encontro ningún empleado con ese ID." << std::endl;
                }
            }
            else {
                std::cout << "No hay empleados registrados." << std::endl;
            }
            break;
        }
        case 4: {
            if (!empleados.empty()) {
                std::string idEliminar;
                std::cout << "Ingrese el ID del empleado a eliminar: ";
                std::cin >> idEliminar;

                auto it = std::find_if(empleados.begin(), empleados.end(), [idEliminar](const Empleado& empleadoEliminar) {
                    return empleadoEliminar.getId() == idEliminar;
                    });

                if (it != empleados.end()) {
                    empleados.erase(it);
                    std::cout << "Empleado eliminado correctamente." << std::endl;
                }
                else {
                    std::cout << "No se encontro ningún empleado con ese ID." << std::endl;
                }
            }
            else {
                std::cout << "No hay empleados registrados." << std::endl;
            }
            break;
        }
        case 5:
            std::cout << "Saliendo." << std::endl;
            break;
        default:
            std::cout << "Opcion no valida." << std::endl;
        }

    } while (opcion != 5);

    return 0;
}
