#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"
# include <iostream>
# include <exception>
# include <string>
# include <limits>
# include "Factory.hpp"

#define MAX(a, b) ((a) > (b)) ? (a) : (b);

template<class T> class Operand : public IOperand {
private:
	Operand(void);
protected:
	std::string _value;
	eOperandType _type;
public:
	Operand(T value);
	Operand(eOperandType type, std::string str);
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