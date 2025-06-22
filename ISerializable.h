#pragma once
#include <fstream>
#include <string>
using namespace std;

class ISerializable {
public:
	virtual void serializar(ofstream&) = 0;
}; 

class SerializadorBinario {
public:
    // Escritura binaria
    static void write(ofstream& out, int valor) {
        out.write(reinterpret_cast<const char*>(&valor), sizeof(int));
    }

    static void write(ofstream& out, double valor) {
        out.write(reinterpret_cast<const char*>(&valor), sizeof(double));
    }

    static void write(ofstream& out, char valor) {
        out.write(&valor, sizeof(char));
    }

    static void write(ofstream& out, const string& valor) {
        size_t longitud = valor.size();
        out.write(reinterpret_cast<const char*>(&longitud), sizeof(size_t));
        out.write(valor.c_str(), longitud);  // No se guarda el '\0'
    }

    // Lectura binaria
    static int readInt(ifstream& in) {
        int valor;
        in.read(reinterpret_cast<char*>(&valor), sizeof(int));
        return valor;
    }

    static double readDouble(ifstream& in) {
        double valor;
        in.read(reinterpret_cast<char*>(&valor), sizeof(double));
        return valor;
    }

    static char readChar(ifstream& in) {
        char valor;
        in.read(&valor, sizeof(char));
        return valor;
    }

    static string readString(ifstream& in) {
        size_t longitud;
        in.read(reinterpret_cast<char*>(&longitud), sizeof(size_t));
        string valor(longitud, '\0');
        in.read(&valor[0], longitud);  // Leer los caracteres
        return valor;
    }
};