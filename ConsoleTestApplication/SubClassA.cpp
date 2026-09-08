#include "SubClassA.h"

SubClassA::SubClassA(double _value) : BaseClass(_value) {


	this->_value = _value;

}

SubClassA::~SubClassA() {



}

void SubClassA::show() {

	std::cout << "Sub Class A\n"; 

}
