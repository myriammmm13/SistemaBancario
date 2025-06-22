#pragma once

template <typename T>
class IIterador {
public:
	virtual bool hasMore() const = 0;
	virtual T next() = 0;
};