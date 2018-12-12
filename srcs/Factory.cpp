#include "../inc/Factory.hpp"
#include "../inc/Operand.hpp"

Factory::Factory(){}

Factory::~Factory(){}

Factory::Factory(Factory const & src)
{
	static_cast<void>(src);
}

Factory &Factory::operator=(Factory const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

IOperand const * Factory::createInt8(std::string const & value) const
{
	return new Operand<int8_t>(std::stoi(value));
}

IOperand const * Factory::createInt16(std::string const & value) const
{
	return new Operand<int16_t>(std::stoi(value));
}

IOperand const * Factory::createInt32(std::string const & value) const
{
	return new Operand<int32_t>(std::stoi(value));
}

IOperand const * Factory::createFloat(std::string const & value) const
{
	return new Operand<float>(std::stof(value));
}

IOperand const * Factory::createDouble(std::string const & value) const
{
	return new Operand<double>(std::stod(value));
}	

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const
{
	const IOperand *(Factory::*func[5])(std::string const & value) const = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	IOperand const * newOperand = (this->*func[type])(value);
	return newOperand;
}

Factory::OutOfRange::OutOfRange(){}

Factory::OutOfRange::~OutOfRange() throw(){}

char const * Factory::OutOfRange::what(void) const throw()
{
	return "Impossible value.";
}

/*

The assembly program includes one or several lexical errors or syntactic errors
An instruction is unknown
Overflow on a value
Underflow on a value
Instruction pop on an empty stack
Division/modulo by 0
The program doesn’t have an exit instruction
An assert instruction is not true
The stack is composed of strictly less that two values when an arithmetic instruction is executed.

*/