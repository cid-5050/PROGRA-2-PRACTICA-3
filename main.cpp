#include <iostream>
#include "tipos.h"
#include "fila.h"
#include "fila2.h"

int main() {
    Persona p {"Julia Perez", 31},
            p1{"Pepe Perez", 30},
            p2{"Toni Martin", 21},
            p3{"Ana Martinez", 27},
            p4{"Federico", 18};

    Fila panaderia;

    try {
        std::cout << "Fila vacia?..." << panaderia.empty()
                  << " Tamano fila?..." <<  panaderia.size()
                  << " " <<  panaderia.getFront().nombre << " "
                  << panaderia.getBack().nombre << std::endl;

    } catch(const std::string &e) {
        std::cout << "Excepcion capturada. " << e << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Llega Julia a la fila..." << std::endl;

    panaderia.push(p);

    std::cout << std::endl;

    std::cout << "Esta Federico 18?... " << panaderia.PersonPresent(p4)
              << std::endl;
    std::cout << "Esta Ana Martinez 27?... " << panaderia.PersonPresent(p3)
              << std::endl;
    std::cout << std::endl;

    std::cout << "Status fila pan..." << panaderia.empty() << " "
              << panaderia.size() << " " <<  panaderia.getFront().nombre
              << " " << panaderia.getBack().nombre << std::endl;

    std::cout << std::endl;

    std::cout << "Llega Pepe a la fila..." << std::endl;

    panaderia.push(p1);

    std::cout << std::endl;

    std::cout << "Status fila pan..." << panaderia.empty() << " "
              << panaderia.size() << " " <<  panaderia.getFront().nombre
              << " " << panaderia.getBack().nombre << std::endl;

    panaderia.push(p2);

    std::cout << std::endl;

    std::cout << "Llega Toni a la fila..." << std::endl;

    std::cout << std::endl;

    std::cout << "Status fila pan..." << panaderia.empty() << " "
              <<  panaderia.size() << " " <<  panaderia.getFront().nombre
              << " " << panaderia.getBack().nombre << std::endl;

    panaderia.push(p3);

    std::cout << std::endl;

    std::cout << "Llega Ana a la fila..." << std::endl;

    std::cout << std::endl;

    std::cout << "Status fila pan..." << panaderia.empty() << " "
              <<  panaderia.size() << " " <<  panaderia.getFront().nombre
              << " " << panaderia.getBack().nombre << std::endl;

    std::cout << std::endl;

    std::cout << "Esta Federico 18?... " << panaderia.PersonPresent(p4) << std::endl;
    std::cout << "Esta Ana Martinez 27?... " << panaderia.PersonPresent(p3) << std::endl;
    std::cout << "Toni Martin 21?... " << panaderia.PersonPresent(p2) << std::endl;
    std::cout << "Esta Pepe Perez 30?... " << panaderia.PersonPresent(p1) << std::endl;
    std::cout << "Esta Julia Perez 31?... " << panaderia.PersonPresent(p) << std::endl;

    std::cout << std::endl;

    std::cout << "Gente en la fila del pan... " << panaderia;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Se corta la fila en p1..." << std::endl;

    Fila fila2;
    try {
         fila2 = panaderia.Split(p1);
    } catch (const std::string &e) {
        std::cout << "Excepcion capturada. " << e << std::endl;
    }

    std::cout << "Gente en la fila original... " << panaderia;
    std::cout << std::endl;
    std::cout << "Gente en la nueva fila... " << fila2;

    std::cout << std::endl;
    std::cout << std::endl;

    Fila2 panaderia2;
    panaderia2.push(p);
    panaderia2.push(p1);
    panaderia2.push(p2);
    panaderia2.push(p3);

    std::cout << "Gente en la fila del pan 2... " << panaderia2;

    panaderia2.pop();

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Gente en la fila del pan 2... " << panaderia2;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Fin." << std::endl;
    std::cout << std::endl;

    return 0;
}
