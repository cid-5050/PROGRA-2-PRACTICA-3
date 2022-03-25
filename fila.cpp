#include "fila.h"

int Fila::size() const{
    int cont=0;
    std::shared_ptr<Elemento> aux=_ultimo;

    if(aux!=nullptr)
    {//Ojo con indireccionar el nullptr... segmentation fault...
        cont++; //Contamos el primer elemento de la lista simplemente enlazada

        while(aux->next!=nullptr)
        {
            cont++; //Contamos uno
            aux=aux->next; //avanzamos en la fila
        }

    }

    return cont;
}

bool Fila::empty() const{
    if (this->size()==0)
    {//Dede un método podemos usar otros métodos
        return true;
    }

    //Otra manera menos costosa computacionalmente
    /*if(_ultimo==nullptr)
    {
        return true;
    }*/

    return false;
}

Persona Fila::getBack()const{ //Devolvemos la última persona de la fila
    return _ultimo->dato;
}

Persona Fila::getFront() const{ //Recorremos la fila buscando el primero
    std::shared_ptr<Elemento> aux=_ultimo;
    if(_ultimo!=nullptr)
    {
        while(aux->next!=nullptr)
        {
            aux=aux->next; //avanzamos en la fila
        }

        return aux->dato;
    }
    else
    {
        throw std::string{"Fila vacia"};
    }
}

void Fila::push(const Persona& dato){ //Llega la persona dato a la fila
    if(_ultimo==nullptr)
    {//No hay nadie en la fila, dato es la primera persona en llegar
        _ultimo=std::make_shared<Elemento>(dato);
    }
    else
    {//Hay mas gente en la fila=> Ponemos dato en último lugar
        std::shared_ptr<Elemento> aux=std::make_shared<Elemento>(dato);
        //"Pedimos vez"
        aux->next=_ultimo; //El que esté delante de la nueva persona será el último de la fila
        //Actualizamos nuestro TAD
        _ultimo=aux; //Actualizamos el puntero a último. Ahora la persona agregada a la lista será la última
    }
}

bool Fila::PersonPresent(const Persona &dato){ //Buscamos a la persona dato en la fila
    std::shared_ptr<Elemento> aux=_ultimo;

    if(_ultimo!=nullptr)
    {
        while(aux->next!=nullptr)
        {
            if(aux->dato==dato) //Atención para poder comparar personas con operador igualdad == debemos indicar como operar mediante sobercarga
            {//Si encontramos a la persona que buscamos devolvemos un true
                return true;
            }
            aux=aux->next; //avanzamos en la fila
        }

        return false; //No hemos encontrado la persona que buscamos
    }
    else
    {
        throw std::string{"Fila vacia"};
    }
}
