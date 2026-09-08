#ifndef VECTOR_H
#define VECTOR_H


namespace Vector {


	class VectorClass
	{

	public:

		double x;
		double y;

		VectorClass(double x, double y);

		// + Operator Overload
		// Note:  Return by value : Always return stack - created objects by value(MyClass), not by reference(MyClass&) or pointer(MyClass*).
		// This Creates a Copy in the Return
		// Do not do this -> return a reference to the VectorClass    VectorClass& it would return the object which goes out of scope in the function once completed!           


		VectorClass operator+(const VectorClass& other) {

			// Created on Stack - scope is just within this function and then destructor called.
			VectorClass resultVectorClass(this->x + other.x, this->y + other.y);

			return resultVectorClass;


		}

		// += Operator Overload
		VectorClass& operator+=(const VectorClass& other) {

			this->x += other.x;
			this->y += other.y;


			return *this;


		}


		void VectorReset(VectorClass& refVectorClass) {

			refVectorClass.x = 0;
			refVectorClass.y = 0;

		}

		




	};



}

#endif
