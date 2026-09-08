#ifndef SUBCLASSA_H
#define SUBCLASSA_H

#include "BaseClass.h"


class SubClassA : public BaseClass  {

public:


	SubClassA(double _value);
	
	~SubClassA() override;

	void show() override;


private:

	double _value;


};








#endif


