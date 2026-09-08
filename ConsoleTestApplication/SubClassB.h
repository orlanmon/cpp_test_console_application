#ifndef SUBCLASSB_H
#define SUBCLASSB_H

#include "BaseClass.h"


class SubClassB : public BaseClass {

public:

	SubClassB(double _value);

	~SubClassB() override;

	void show() override;

private:

	double _value;


};

#endif

