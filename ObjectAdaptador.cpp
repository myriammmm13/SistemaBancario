#include "ObjectAdaptador.h"
#include <typeinfo>
#include <sstream>

string ObjectAdaptador::toString() const {
	return typeid(*this).name();
}

bool ObjectAdaptador::equals(IObjecto* ref) {
	return this == ref;
}

string ObjectAdaptador::getType() const {
	return typeid(*this).name();
}

ostream& operator<<(ostream& os, ObjectAdaptador& p) {
	os << p.toString();
	return os;
}


ostream& operator<<(ostream& os, ObjectAdaptador* p) {
	os << p->toString();
	return os;
}

// bool operator==(ObjectAdaptador& a, ObjectAdaptador& b) {
// 	return a.equals(&b);
// }
// 
// bool ObjectAdaptador::operator==(ObjectAdaptador* b) {
// 	return b->equals(this);
// }