#ifndef FACTORY_HPP
# define FACTORY_HPP

# include <iostream>
# include <exception>
# include <string>
# include "IOperand.hpp"
// # include "Operand.hpp"

class Factory {

public:
	Factory();
	~Factory();
	Factory(Factory const &src);
	Factory &operator=(Factory const &rhs);
	IOperand const * createOperand(eOperandType, std::string const & value) const;
	IOperand const * createInt8(std::string const & value) const;
	IOperand const * createInt16(std::string const & value) const;
	IOperand const * createInt32(std::string const & value) const;
	IOperand const * createFloat(std::string const & value) const;
	IOperand const * createDouble(std::string const & value) const;

	class OutOfRange : public std::exception {
	public:
		OutOfRange(void);
		virtual ~OutOfRange() throw();
		char const *what(void) const throw();
	};

};

#endif