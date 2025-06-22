#pragma once
#include "IIterador.h"

template <typename T>
class IEnumerable {
public:
	virtual IIterador<T>* getIterador() const = 0;
};