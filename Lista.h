#pragma once
#include <sstream>
#include "ObjectAdaptador.h"
#include "Nodo.h"
#include "IColeccion.h"
#include "IIterador.h"
#include "IteradorLista.h"
#include "IEnumerable.h"
using namespace std;
 
template<typename T>
class Lista : public ObjectAdaptador, public IColeccion<T>, public IEnumerable<T> {
private:
    Nodo<T>* root;
public:
    Lista() {
        root = NULL;
    }

    void agregar(T dato) {
        root = new Nodo<T>(dato, root);
    }


    IIterador<T>* getIterador() const {
        return new IteradorLista<T>(root);
    }


    bool removerInicio() {
        if (!vacio()) {
            //
            Nodo<T>* tmp = root;
            root = root->getSiguiente();
            delete tmp;
            return true;
        }
        return false;
    }

    bool vacio() const {
        return root == NULL;
    }

    void clear() {
        while (!vacio()) {
            removerInicio();
        }
    }

    int size() const {
        int contador = 0;
        IIterador<T>* it = getIterador();
        while (it->hasMore()) {
            contador++;
            it->next();
        }
        return contador;
    }

    string toString() const {
        stringstream r;
        IIterador<T>* it = getIterador();
        r << "{";
        while (it->hasMore()) {
            r << it->next();
            if (it->hasMore()) {
                r << ", ";
            }
        }
        r << "}";
        return r.str();
    }

    T get(int pos) const {
        IIterador<T>* it = getIterador();
        while (it->hasMore()) {
            T actual = it->next();
            if (pos-- == 0) {
                return actual;
            }
        }
        throw exception("Elemento no encontrado");
    }

    void agregarFinal(T dato) {
        if (vacio()) {
            agregar(dato);
        }
        else {
            Nodo<T>* actual = root;
            while (actual->getSiguiente() != NULL) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(new Nodo<T>(dato));
        }
    }

    void remover(T dato) {
        root = remover(root, dato);
    }

private:
    Nodo<T>* remover(Nodo<T>* actual, T dato) {
        if (actual == NULL) {
            return NULL;
        }
        else if (comparar(actual->getDato(), dato)) {  // habia dos )) en vez de uno.
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual; // Libera la memoria del nodo
            return siguiente; // Retorna el siguiente nodo para enlazar
        }
        actual->setSiguiente(remover(actual->getSiguiente(), dato));
        return actual;
    }


    template<typename T>
    bool comparar(T a, T b) {
        // Para tipos primitivos y std::string
        if constexpr (
            std::is_fundamental<T>::value ||
            std::is_same<T, std::string>::value
            ) {
            return a == b;
        }
        else {
            // Para clases personalizadas que tienen equals()
            return a->equals(b);
        }
    }
};