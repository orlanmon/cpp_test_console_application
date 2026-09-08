#include "BaseClass.h"


BaseClass::BaseClass(double _value) {


	this->_value = _value;

}

BaseClass::~BaseClass() {



}

void BaseClass::show() { std::cout << "Base Class\n"; } // Declared virtual