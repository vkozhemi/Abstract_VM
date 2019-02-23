#include "../inc/Operand.hpp"

Operand::Operand(eOperandType type, std::string value) {
	this->_type = type;
	this->_value = value;
}

Operand::Operand(Operand const & rhs) {
	*this = rhs;
}

Operand & Operand::operator=(Operand const & rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_value = rhs._value;
	}
	return *this;
}

Operand::~Operand(){}

int Operand::getPrecision(void) const {
	return this->_type;
}

eOperandType 	Operand::getType(void) const {
	return this->_type;
}

IOperand const * Operand::operator+(IOperand const & rhs) const {
	eOperandType type;
	type = std::max(this->getType(), rhs.getType());
	if (type <= 2) {
		Parser p;
		p.validation_size(type, std::to_string(std::stoi(rhs.toString()) + std::stoi(_value)));
		return new Operand(type, std::to_string(std::stoi(rhs.toString()) + std::stoi(_value)));
	}
	else {
		Parser p;
		p.validation_size(type, std::to_string(std::stod(rhs.toString()) + std::stod(_value)));
		return new Operand(type, std::to_string(std::stod(rhs.toString()) + std::stod(_value)));
	}
}

IOperand const * Operand::operator-(IOperand const & rhs) const {
	eOperandType type;
	type = std::max(this->getType(), rhs.getType());
	if (type <= 2) {
		Parser p;
		p.validation_size(type, std::to_string(std::stoi(rhs.toString()) - std::stoi(_value)));
		return new Operand(type, std::to_string(std::stoi(rhs.toString()) - std::stoi(_value)));
	}
	else {
		Parser p;
		p.validation_size(type, std::to_string(std::stod(rhs.toString()) - std::stod(_value)));
		return new Operand(type, std::to_string(std::stod(rhs.toString()) - std::stod(_value)));
	}
}

IOperand const * Operand::operator*(IOperand const & rhs) const {
	eOperandType type;
	type = std::max(this->getType(), rhs.getType());
	if (type <= 2) {
		Parser p;
		p.validation_size(type, std::to_string(std::stoi(rhs.toString()) * std::stoi(_value)));
		return new Operand(type, std::to_string(std::stoi(rhs.toString()) * std::stoi(_value)));
	}
	else {
		Parser p;
		p.validation_size(type, std::to_string(std::stod(rhs.toString()) * std::stod(_value)));
		return new Operand(type, std::to_string(std::stod(rhs.toString()) * std::stod(_value)));
	}
}

IOperand const * Operand::operator/(IOperand const & rhs) const {
	eOperandType type;
	type = std::max(this->getType(), rhs.getType());
	if (type <= 2) {
		Parser p;
		p.validation_size(type, std::to_string(std::stoi(rhs.toString()) / std::stoi(_value)));
		return new Operand(type, std::to_string(std::stoi(rhs.toString()) / std::stoi(_value)));
	}
	else {
		Parser p;
		p.validation_size(type, std::to_string(std::stod(rhs.toString()) / std::stod(_value)));
		return new Operand(type, std::to_string(std::stod(rhs.toString()) / std::stod(_value)));
	}
}

IOperand const * Operand::operator%(IOperand const & rhs) const {
	eOperandType type;
	type = std::max(this->getType(), rhs.getType());
	if (type <= 2) {
		Parser p;
		p.validation_size(type, std::to_string(std::stoi(rhs.toString()) % std::stoi(_value)));
		return new Operand(type, std::to_string(std::stoi(rhs.toString()) % std::stoi(_value)));
	}
	else {
		Parser p;
		p.validation_size(type, std::to_string(fmod(std::stod(rhs.toString()), std::stod(_value))));
		return new Operand(type, std::to_string(fmod(std::stod(rhs.toString()), std::stod(_value))));
	}
}

std::string const & Operand::toString() const {
	return this->_value;
}