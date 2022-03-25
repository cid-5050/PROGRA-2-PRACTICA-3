#include "fila.h"

int Fila::size() const {
    int cont = 0;
    std::shared_ptr<Elemento> aux = _ultimo;

    if(aux != nullptr) {
        cont++;

        while(aux->next != nullptr) {
            cont++;
            aux = aux->next;
        }

    }

    return cont;
}

bool Fila::empty() const {
    if (this->size() == 0) {
        return true;
    }

    /*if(_ultimo == nullptr)
    {
        return true;
    }*/

    return false;
}

Persona Fila::getBack() const {
    return _ultimo->dato;
}

Persona Fila::getFront() const {
    std::shared_ptr<Elemento> aux = _ultimo;
    if(_ultimo != nullptr) {
        while (aux->next != nullptr) {
            aux = aux->next;
        }

        return aux->dato;
    } else {
        throw std::string{"Fila vacia"};
    }
}

void Fila::push(const Persona& dato) {
    if(_ultimo == nullptr) {
        _ultimo = std::make_shared<Elemento>(dato);
    } else {
        std::shared_ptr<Elemento> aux = std::make_shared<Elemento>(dato);
        aux->next = _ultimo;
        _ultimo = aux;
    }
}

bool Fila::PersonPresent(const Persona &dato) {
    std::shared_ptr<Elemento> aux = _ultimo;

    if(_ultimo != nullptr) {
        while(aux->next != nullptr) {
            if(aux->dato == dato) {
                return true;
            }
            aux = aux->next;
        }

        return false;
    } else {
        throw std::string{"Fila vacia"};
    }
}

Fila Fila::Split(const Persona& dato) {
    std::shared_ptr<Elemento> elemAux;
    Fila filaAux;

    if (_ultimo != nullptr) {
        if (not (elemAux->next->dato == dato)) {
            do {
                elemAux = elemAux->next;
            } while (not (elemAux->next->dato == dato));
        }

        elemAux->next = nullptr;
        filaAux._ultimo = std::make_shared<Elemento>(dato);
    } else {
        throw std::string{"Fila vacia"};
    }

    return filaAux;
}
