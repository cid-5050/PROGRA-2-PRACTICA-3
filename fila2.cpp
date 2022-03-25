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
    return _ultimo->dato;
}

Persona Fila2::getFront() const {
    std::shared_ptr<Elemento2> aux = _ultimo;
    if(_ultimo != nullptr) {
        while (aux->next != nullptr) {
            aux = aux->next;
        }

        return aux->dato;
    } else {
        throw std::string{"Fila2 vacia"};
    }
}

void Fila2::push(const Persona& dato) {
    if(this->empty()) {
        _primero = std::make_shared<Elemento2>(dato);
        _ultimo = std::make_shared<Elemento2>(dato);
    } else {
        std::shared_ptr<Elemento2> aux = std::make_shared<Elemento2>(dato);
        aux->next = _ultimo;
        _ultimo = aux;
    }
}

/*
bool Fila2::PersonPresent(const Persona &dato) {
    std::shared_ptr<Elemento2> aux = _ultimo;

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
*/

int Fila2::PersonPresent(const Persona &dato) {
    int cont = 0;
    std::shared_ptr<Elemento2> aux = _ultimo;

    if(_ultimo != nullptr) {

        while(aux != nullptr) {
            if(aux->dato == dato) {
                return (this->size() - cont);
            }

            aux = aux->next;
            cont++;
        }

        return -1;
    } else {
        throw std::string{"Fila vacia"};
    }
}

Fila2 Fila2::Split(const Persona& dato) {
    std::shared_ptr<Elemento2> elemAux = _ultimo;
    Fila2 filaAux;

    if (_ultimo != nullptr) {
        if (not (elemAux->next->dato == dato)) {
            do {
                elemAux = elemAux->next;
            } while (not (elemAux->next->dato == dato));
        }

        filaAux._ultimo = elemAux->next;
        elemAux->next = nullptr;
    } else {
        throw std::string{"Fila vacia"};
    }

    return filaAux;
}
