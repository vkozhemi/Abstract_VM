#ifndef INTERPRETER_HPP
# define INTERPRETER_HPP

# include <string>
# include <iostream>
# include <regex>
# include <vector>
# include <fstream>
# include <cmath>
# include <iterator>
# include <iomanip>
# include <cstdlib>
# include <algorithm>  

# include "Operand.hpp"
# include "IOperand.hpp"
# include "Lexer.hpp"
# include "Parser.hpp"
# include "Factory.hpp"
# include "Exceptions.hpp"
# include "Token.hpp"

class Interpreter
{
private:
	int								calcWidh();
	int								width;
	std::string						convertType(eOperandType type);
	size_t							size;
	unsigned int 					end_time;

public:
	Interpreter();
	~Interpreter();
	Factory							factory;

	void							push(eOperandType type, std::string value, std::string dt);
	void							assert(eOperandType type, std::string value);
	void							pop();
	void							dump();
	void							print();
	void							ssqrt();
	void							min();
	void							max();
	void							clear();
	void							stop();
	void							info();
	void 							operations(eOperation operation);
	void							print(std::vector<Token> token);
	std::vector<const IOperand*>	stack;
	std::vector<std::string>		stack_time;

};

#endif