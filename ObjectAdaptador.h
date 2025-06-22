#pragma once
#include "IObjecto.h"

/*
	El patrón adaptador
	consiste en implementar 
	una interface, a sus comportamientos
	genéricos.
*/
class ObjectAdaptador : public IObjecto {
public:
	virtual string toString() const override;
	virtual bool equals(IObjecto*) override;
	virtual string getType() const override;
	//bool operator==(ObjectAdaptador*);
};
ostream& operator<<(ostream&, ObjectAdaptador&);
ostream& operator<<(ostream&, ObjectAdaptador*);
//bool operator==(ObjectAdaptador&, ObjectAdaptador&);