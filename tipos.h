#ifndef TIPOS_H_
#define TIPOS_H_

#include <string>
#include <memory>

struct Persona{
    std::string nombre;
    int edad{0};

     bool operator == (const Persona &op2) const{
             if(op2.nombre == this->nombre and op2.edad == this->edad) {
                 return true;
             }
             return false;
     }
};

struct Elemento{
    explicit Elemento (const Persona &p) {dato = p;}
    Persona dato;
    std::shared_ptr<Elemento> next{nullptr};
};

struct Elemento2{
    explicit Elemento2 (const Persona &p) {dato = p;}
    Persona dato;
    std::shared_ptr<Elemento2> next{nullptr};
    std::shared_ptr<Elemento2> prev{nullptr};
};

#endif // TIPOS_H_
