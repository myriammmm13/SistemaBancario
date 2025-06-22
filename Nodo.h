#pragma once
#include <string>
#include "ObjectAdaptador.h"

template<typename T>
class Nodo : public ObjectAdaptador {
private:
	Nodo<T>* _siguiente;
	T _dato;
public:

    Nodo(T dato, Nodo<T>* sig = NULL) {
        _dato = dato;
        _siguiente = sig;
    }

    void setSiguiente(Nodo<T>* sig) {
        _siguiente = sig;
    }

    void setDato(T dato) {
        _dato = dato;
    }

    Nodo<T>* getSiguiente() const {
        return _siguiente;
    }

    T getDato() const {
        return _dato;
    }
};