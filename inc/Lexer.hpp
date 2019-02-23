#ifndef LEXER_H
# define LEXER_H

# include <string>
# include <iostream>
# include <regex>
# include <vector>
# include <fstream>
# include <cmath>
# include <ctime>

# include "IOperand.hpp"
# include "Operand.hpp"
# include "Parser.hpp"
# include "Factory.hpp"
# include "Exceptions.hpp"
# include "Token.hpp"

class Lexer
{
private:
	bool							_error;
	unsigned int					i;
	void							command(std::string str);
	
//-----------------Token---------------------
	std::vector<Token>				vector;
	eOperation						getOperation(std::string str);
	eOperandType 					getType(std::string str);
	std::string						getValue(std::string str);
//-------------------------------------------
	
public:
	Lexer();
	Lexer(Lexer const &obj);
	Lexer							&operator=(Lexer const &hrs);
	~Lexer();
	void							validation(std::vector<std::string> array, std::vector<std::string> array_time);
	void							PrintStack();
	std::vector<Token> 				getToken() const;
	bool							_stop;
	bool							_exit;
};

#endif