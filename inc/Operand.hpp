#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include "Factory.hpp"
# include "IOperand.hpp"

template<class T> class Operand : public IOperand {

protected:
	std::string _value;

public:
	Operand(void);
	Operand(T value);
	Operand(std::string str);
	Operand(Operand const & obj);
	Operand & operator=(Operand const *rhs);
	~Operand(void);

	int 				getPrecision( void ) const = 0;  // Precision of the type of the instance
	eOperandType 		getType( void ) const = 0; // Type of the instance

	IOperand const * 	operator+( IOperand const & rhs ) const = 0; // Sum
	IOperand const * 	operator-( IOperand const & rhs ) const = 0; // Difference 
	IOperand const * 	operator*( IOperand const & rhs ) const = 0; // Product
	IOperand const * 	operator/( IOperand const & rhs ) const = 0; // Quotient
	IOperand const * 	operator%( IOperand const & rhs ) const = 0; // Modulo

	std::string const & toString( void ) const = 0; // String representation of the instance

	~IOperand( void ) {}

};

#endif