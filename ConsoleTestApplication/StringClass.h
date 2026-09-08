
#ifndef STRINGCLASS_H
#define STRINGCLASS_H

#include <string.h>
#include <iostream>

class StringClass {


private:
	
	std::string m_buffer;

public:


	StringClass(const std::string& string_buffer) {

	
		m_buffer = string_buffer;

	}


	~StringClass() {

		m_buffer.clear();

	}


	// Note Important Distinction when performing assignments
	// A copy constructor is called when a new object is created using an existing object.
	// An assignment operator is called when an already existing object is assigned the value of another existing object.

	// Copy Constructor
	StringClass(const StringClass& other) {

		
		// std:string - this performs a copy
		this->m_buffer = other.m_buffer;

		std::cout << "String Class copy constructor called.";


	}




	// Overload = Operator
	StringClass& operator=(const StringClass& other) {


		std::cout << "StringClass = Operator Overload Called";

		this->m_buffer.clear();

		// This Performs a Copy of the String
		this->m_buffer = other.m_buffer;
		
		return *this;

	}
	
	friend std::ostream& operator<<(std::ostream& stream, const StringClass& outputStringClass);



};

// Function to Overload Output Stream Operator << 
std::ostream& operator<<(std::ostream& stream, const StringClass& outputStringClass) {

	stream << outputStringClass.m_buffer;

	return stream;

}

#endif // !STRINGCLASS_H

