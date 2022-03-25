#include "fila2.h"

int Fila2::size() const {
    int cont = 0;
    std::shared_ptr<Elemento2> aux = _ultimo;

    if(aux != nullptr) {
        cont++;

        while(aux->next != nullptr) {
            cont++;
            aux = aux->next;
        }

    }

    return cont;
}

bool Fila2::empty() const {
    if (this->size() == 0) {
        return true;
    }

    return false;
}

Persona Fila2::getBack() const {
    if (not (this->empty())) {
        return _ultimo->dato;
    } else {
        throw std::string{"Fila vacia"};
    }
}

Persona Fila2::getFront() const{ //Recorremos la Fila2 buscando el primero
    if (not (this->empty())) {
        return _primero->dato;
    } else {
        throw std::string{"Fila vacia"};
    }
}

void Fila2::push(const Persona& dato) {
    std::shared_ptr<Elemento2> aux = std::make_shared<Elemento2>(dato);

    if(this->empty()) {
        _primero = aux;
        _ultimo = aux;
    } else {
        _ultimo->prev = aux;
        aux->next = _ultimo;
        _ultimo = aux;
    }
}

Persona Fila2::pop(void)
{
    std::shared_ptr<Elemento2> aux=_primero->prev;
    Persona auxFront = getFront();
    if(_ultimo!=nullptr)
    {
        aux->next=nullptr;
        return auxFront;
    }
    else
    {
        throw std::string{"Fila vacia"};
    }
}

