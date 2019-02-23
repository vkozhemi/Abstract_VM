#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>

class UnderflowException : std::underflow_error {

public:
	UnderflowException(const std::string &s) : underflow_error(s), str(s) {}

	virtual const char *what() const throw() override {
		return str.c_str();
	}
private:
	std::string str;
};

class OverflowException : std::overflow_error {

public:
	OverflowException(const std::string &s) : overflow_error(s), str(s) {}

	virtual const char *what() const throw() override {
		return str.c_str();
	}
private:
	std::string str;
};

class PushException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Push error";
	}
};


class AssertValueException : public std::exception {

public:
	virtual const char *what() const throw() {
		return (" An assert instruction is not true, wrong value");
	}
};

class AssertTypeException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " An assert instruction is not true, wrong type";
	}
};

class AssertEmptyStackException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Instruction assert on an empty stack";
	}
};

class PopEmptyStackException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Instruction pop on an empty stack";
	}
};

class EmptyStackException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Empty stack";
	}
};

class NotCharException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Value is not int8";
	}
};

class NotExitException : public std::exception {

public:
	virtual const char *what() const throw() {
		return "The program doesn’t have an exit instruction";
	}
};

class DumpEmptyStackException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Instruction dump on an empty stack";
	}
};

class OperationException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " The stack is composed of strictly less that two values when an arithmetic instruction is executed";
	}
};

class DivisionByZeroException : public std::exception {

public:
	virtual const char *what() const throw() {
		return " Division/modulo by 0";
	}
};

class StopException : public std::exception {

public:
	virtual const char *what() const throw() {
		return "Program has been stopped";
	}
};

#endif