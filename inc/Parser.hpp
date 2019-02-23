#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <iostream>
# include <regex>
# include <vector>
# include <fstream>
# include <cmath>
# include <iterator>

# include "Operand.hpp"
# include "IOperand.hpp"
# include "Lexer.hpp"
# include "Factory.hpp"
# include "Exceptions.hpp"
# include "Interpreter.hpp"

class Parser
{
private:
	bool							_error;
	size_t							size;

public:
	Parser();
	Parser(Parser const &rhs);
	~Parser();
	void							parser(std::vector<Token> token);
	void							PrintStack();
	Factory							factory;
	unsigned int 					i;
	void							validation_size(eOperandType type, std::string value);
};

#endif