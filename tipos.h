#ifndef TIPOS_H
#define TIPOS_H

#include <string>
#include <memory>

struct Persona{
    std::string nombre;
    int edad{0};

     bool operator ==(const Persona &op2) const{
             if(op2.nombre==this->nombre and op2.edad==this->edad)
             {
                 return true;
             }
             return false;
     }
};

struct Elemento{
    Elemento(const Persona &p){dato=p;}
    Persona dato;
    std::shared_ptr<Elemento> next{nullptr};
};

struct Elemento2{
    Elemento2(const Persona &p){dato=p;}
    Persona dato;
    std::shared_ptr<Elemento> next{nullptr};
    std::shared_ptr<Elemento> prev{nullptr};
};

#endif // TIPOS_H
