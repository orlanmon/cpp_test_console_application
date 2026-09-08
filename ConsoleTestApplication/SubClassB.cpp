#include "SubClassB.h"

SubClassB::SubClassB(double _value) : BaseClass(_value) {


	this->_value = _value;

}

SubClassB::~SubClassB() {



}

void SubClassB::show() {

	std::cout << "Sub Class B\n";

}
