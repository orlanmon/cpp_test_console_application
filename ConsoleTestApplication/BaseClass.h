#ifndef BASECLASS_H
#define BASECLASS_H

#include <iostream>

class BaseClass {

public:


	BaseClass(double _value);


	virtual ~BaseClass();


	virtual void show();


private:

	double _value;


};



#endif

