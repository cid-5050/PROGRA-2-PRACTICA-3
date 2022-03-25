#ifndef FILA2_H_
#define FILA2_H_

#include <iostream>
#include <memory>
#include "tipos.h"

class Fila2 {
    public:
        int size() const;
        bool empty() const;
        Persona getFront() const;
        Persona getBack() const;
        void push(const Persona& dato);
        // bool PersonPresent(const Persona& dato);
        int PersonPresent(const Persona& dato);
        Fila2 Split(const Persona& dato);

    private:
        std::shared_ptr<Elemento2> _primero = nullptr;
        std::shared_ptr<Elemento2> _ultimo = nullptr;

        friend std::ostream& operator<<(std::ostream& os, const Fila2& f){
            std::shared_ptr<Elemento2> aux = f._ultimo;
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



#endif // FILA2_H_
