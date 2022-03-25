#ifndef FILA_H_
#define FILA_H_

#include <iostream>
#include <memory>
#include "tipos.h"

class Fila {
    public:
        int size() const;
        bool empty() const;
        Persona getFront() const;
        Persona getBack() const;
        void push(const Persona& dato);
        bool PersonPresent(const Persona& dato);
        Fila Split(const Persona& dato);

    private:
        std::shared_ptr<Elemento> _ultimo = nullptr;
        friend std::ostream& operator<<(std::ostream& os, const Fila& f){
            std::shared_ptr<Elemento> aux = f._ultimo;
            if (aux != nullptr) {
                os << aux->dato.nombre << "_";
                while (aux->next != nullptr) {
                    aux = aux->next;
                    os << aux->dato.nombre << "_";
                }

            }
            return os;
        }
};



#endif // FILA_H_
