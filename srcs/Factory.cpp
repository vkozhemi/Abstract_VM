#include "../inc/Factory.hpp"
#include "../inc/Operand.hpp"

Factory::Factory(){}

Factory::~Factory(){}

Factory::Factory(Factory const & src) {
	*this = src;
}

Factory &Factory::operator=(Factory const & rhs)
{
	if (this != &rhs)
	{
		//*this = rhs;
	}
	return *this;
}

IOperand const * Factory::createInt8(std::string const & value) const {
	return new Operand(Int8, value);
}

IOperand const * Factory::createInt16(std::string const & value) const {
	return new Operand(Int16, value);
}

IOperand const * Factory::createInt32(std::string const & value) const {
	return new Operand(Int32, value);
}

IOperand const * Factory::createFloat(std::string const & value) const {
	return new Operand(Float, value);
}

IOperand const * Factory::createDouble(std::string const & value) const {
	return new Operand(Double, value);
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const
{
	if (type == Int8)
		return createInt8(value);
	else if (type == Int16)
		return createInt16(value);
	else if (type == Int32)
		return createInt32(value);
	else if (type == Float)
		return createFloat(value);
	else if (type == Double)
		return createDouble(value);
	return nullptr;
}
