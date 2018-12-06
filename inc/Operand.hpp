#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include "Factory.hpp"


template<class T> class Operand : public IOperand {

protected:
	std::string _value;
public:
	Operand(void);
	Operand(T value);
	Operand(std::string str);
	Operand(Operand const & src);
	~Operand(void);
	Operand & operator=(Operand const & rhs);
	int 			 getPrecision(void) const;
	eOperandType 	 getType(void) const;
	IOperand const * operator+(IOperand const & rhs) const;
	IOperand const * operator-(IOperand const & rhs) const;
	IOperand const * operator*(IOperand const & rhs) const;
	IOperand const * operator/(IOperand const & rhs) const;
	IOperand const * operator%(IOperand const & rhs) const;
	std::string const & toString(void) const;

	class DivideByZero : public std::exception
	{
	public:
		DivideByZero(void){};
		virtual ~DivideByZero() throw(){};
		char const * what(void) const throw()
		{
			return "Impossible divide by zero.";
		}
	};

	class UnderflowException : public std::exception
	{
	public:
		UnderflowException(void){};
		virtual ~UnderflowException() throw(){};
		char const * what(void) const throw()
		{
			return "Underflow Exception.";
		}
	};

	class OverflowException : public std::exception
	{
	public:
		OverflowException(void){};
		virtual ~OverflowException() throw(){};
		char const * what(void) const throw()
		{
			return "Overflow Exception.";
		}
	};
};

#endif