#pragma once
#include <type_traits>
#include <fstream>
#include "Lista.h"
#include "ISerializable.h"

template<typename T>
class ListaSerializable : public Lista<T>, public ISerializable {
public:
    ListaSerializable() {}

    ListaSerializable(ifstream& file) {
        static_assert(std::is_base_of<ISerializable, typename std::remove_pointer<T>::type>::value, "T debe heredar de ISerializable");
        static_assert(std::is_constructible<typename std::remove_pointer<T>::type, ifstream&>::value, "T debe tener constructor T(ifstream&)");
        int cantidad = SerializadorBinario::readInt(file);
        for (int i = 0; i < cantidad; ++i) {
            // Si T es un puntero (como Persona*), entonces creamos new Persona(file)
            this->agregarFinal(new typename std::remove_pointer<T>::type(file));
        }
    }

    virtual void serializar(ofstream& file) override {
        static_assert(std::is_base_of<ISerializable, typename std::remove_pointer<T>::type>::value, "T debe heredar de ISerializable");
        SerializadorBinario::write(file, this->size());
        IIterador<T>* it = this->getIterador();
        while (it->hasMore()) {
            T dato = it->next();
            dato->serializar(file);  
            // Asume que T es puntero a clase con método serializar()
        }
        delete it;
    }
};