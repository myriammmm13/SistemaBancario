#pragma once

template<typename T>
class IColeccion {
public:
	virtual void agregar(T) = 0;
	virtual void remover(T) = 0;
	virtual bool removerInicio() = 0;
	virtual void clear() = 0; // limpia todo
	virtual int size() const = 0;
	virtual T get(int) const = 0;
};