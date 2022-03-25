#include <iostream>
#include "tipos.h"
#include "fila.h"

using namespace std;

int main()
{
    Persona p{"Julia Perez",31},p1{"Pepe Perez",30},p2{"Toni Martin",21},p3{"Ana Martinez",27},p4{"Federico",18};

    //Elemento e{p},e1{p1},e2{p2},e3{p3};

    Fila panaderia;

    try{
        std::cout<<"Fila vacia?..."<<panaderia.empty()<<" Tamaño fila?..."<< panaderia.size()<<" "<< panaderia.getFront().nombre<<" "<<panaderia.getBack().nombre<<std::endl;
    }
    catch(const string &e)
    {
        std::cout<<"Excepcion capturada. "<<e<<endl;
    }

    std::cout<<std::endl;

    std::cout<<"Llega Julia a la fila..."<<std::endl;
    panaderia.push(p);
    std::cout<<std::endl;

    std::cout<<"Esta Federico 18?... "<<panaderia.PersonPresent(p4)<<std::endl;
    std::cout<<"Esta Ana Martinez 27?... "<<panaderia.PersonPresent(p3)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Status fila pan..."<<panaderia.empty()<<" "<< panaderia.size()<<" "<< panaderia.getFront().nombre<<" "<<panaderia.getBack().nombre<<std::endl;

    std::cout<<"Llega Pepe a la fila..."<<std::endl;
    panaderia.push(p1);
    std::cout<<"Status fila pan..."<<panaderia.empty()<<" "<< panaderia.size()<<" "<< panaderia.getFront().nombre<<" "<<panaderia.getBack().nombre<<std::endl;
    panaderia.push(p2);
    std::cout<<"Llega Toni a la fila..."<<std::endl;
    std::cout<<"Status fila pan..."<<panaderia.empty()<<" "<< panaderia.size()<<" "<< panaderia.getFront().nombre<<" "<<panaderia.getBack().nombre<<std::endl;
    panaderia.push(p3);
    std::cout<<"Llega Ana a la fila..."<<std::endl;
    std::cout<<"Status fila pan..."<<panaderia.empty()<<" "<< panaderia.size()<<" "<< panaderia.getFront().nombre<<" "<<panaderia.getBack().nombre<<std::endl;

    std::cout<<"Esta Federico 18?... "<<panaderia.PersonPresent(p4)<<std::endl;
    std::cout<<"Esta Ana Martinez 27?... "<<panaderia.PersonPresent(p3)<<std::endl;

    std::cout<<"Gente en la fila del pan... "<<panaderia;

    return 0;
}
