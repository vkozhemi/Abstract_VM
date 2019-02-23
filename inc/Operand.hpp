#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include <cmath>

# include "IOperand.hpp"
# include "Factory.hpp"
# include "Operand.hpp"
# include "Parser.hpp"
# include "Exceptions.hpp"
# include "Token.hpp"

#define MAX(a, b) ((a) > (b)) ? (a) : (b);

class Operand : public IOperand {
private:
	std::string		_value;
	eOperandType	_type;
public:
	Operand(eOperandType type, std::string value);
	Operand(Operand const & src);
	Operand & operator=(Operand const & rhs);
	~Operand(void);
	int				 getPrecision(void) const;
	eOperandType 	 getType(void) const;
	IOperand const * operator+(IOperand const & rhs) const;
	IOperand const * operator-(IOperand const & rhs) const;
	IOperand const * operator*(IOperand const & rhs) const;
	IOperand const * operator/(IOperand const & rhs) const;
	IOperand const * operator%(IOperand const & rhs) const;
	std::string const & toString(void) const;

};

#endif